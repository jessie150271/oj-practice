using System;
using System.Drawing;
using System.Windows.Forms;
using System.Linq;
using System.Collections.Generic;

namespace ArrayToDtGridView
{    
    /*
     * @Author: Jessie Huang
     * @Date: 2020-02-14
     * @Last Modified by: Jessie Huang
     * @Last Modified time: 2020-02-17
     */
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public int r, c, n;     //r,c分別表列、行數
        public float[,] score = new float[7, 8];
        public bool IsStatistics = false;
        public int[] sortFlag = new int[8] { -1, -1, -1, -1, -1, -1, -1, -1 }; //-1:為排序 0:已排序ASC 1:已排序DESC

        private void Form1_Load(object sender, EventArgs e)
        {
            //設定行、列數
            grv.ColumnCount = 8;                        //行數固定8
            grv.RowCount=7;                             //列數(欄名+人數+科平均)
            grv.Font = new Font("Arial", 12, FontStyle.Regular);        //字型,大小,字體
            //grv.GridColor = System.Drawing.Color.FromArgb(0, 0, 192);   //cell框線顏色 
            grv.BackgroundColor = System.Drawing.Color.FromArgb(255, 255, 204);   //dtGrid 背景色
            //grv.Columns[7].Width = 100;              //個別欄寬，本範例以自動欄寬，故不需要使用。
            grv.ColumnHeadersVisible = false;
            grv.RowHeadersVisible = false;
                       
            //加入排序事件
            grv.CellContentClick += new DataGridViewCellEventHandler(Grv_CellContentClick);
            grv.EditMode = DataGridViewEditMode.EditProgrammatically;

            btn1_Click(sender, e);
        }

        
        private void btn1_Click(object sender, EventArgs e)
        {
            //未統計
            IsStatistics = false;
            //重置排序
            sortFlag = new int[] { -1, -1, -1, -1, -1, -1, -1, -1 };


            int i, j;
            n = Convert.ToInt32(numericUpDown1.Value);       //人數
            //n = 5;                                      //本例為基礎 設定n=5，暫不取使用者輸入值 
            r = n + 2;
            c = 8;
            grv.ColumnCount = c;                        //行數固定8
            grv.RowCount = r;                           //列數(欄名+人數+科平均)
            //清除grv內容
            for (j = 0; j < c; j++)
            {
                for (i = 0; i < r; i++)
                {
                    grv[j, i].Value = "";
                    grv[j, i].Style.BackColor = System.Drawing.Color.FromArgb(255, 255, 204);   //grv Cell 背景色 淺黃
                    grv[j, i].Style.ForeColor = System.Drawing.Color.FromArgb(0, 0, 0);         //恢復黑色字
                }
            }

            //欄名(上及左)背景色
            for (j = 0; j < c; j++)
                grv[j, 0].Style.BackColor = System.Drawing.Color.LightSkyBlue;     //欄名cell背景色 淺藍

            //表頭文字顏色
            for (i = 0; i < c; i++)
            {
                grv[i, 0].Style.ForeColor = Color.MediumBlue; 
            }
            grv[0, r - 1].Style.ForeColor = Color.MediumBlue;

            for (i = 1; i < r; i++)
                grv[0, i].Style.BackColor = System.Drawing.Color.LightSkyBlue;     //左cell背景色 淺紫

            //表頭文字顏色
            for (i = 1; i < r-1; i++)
            {
                grv[0, i].Style.ForeColor = Color.Green;
            }

            //score 陣列長度指定(變動)Rezise
            score = new float[r, c];

            //列標題

            grv[0, 0].Value = "座號";
            grv[1, 0].Value = "國文";
            grv[2, 0].Value = "英文";
            grv[3, 0].Value = "數學";
            grv[4, 0].Value = "總分";
            grv[5, 0].Value = "平均";
            grv[6, 0].Value = "名次";
            grv[7, 0].Value = "不及格科數";
            //行標題的各科平均
            grv[0, r-1].Value = "科平均";
            
            Rand(); //取亂數
           
            //將分數、總分、各人平均轉到grv
            double sum;
            for (i = 1; i <= n; i++) 
            {
                sum = 0;
                for (j = 0; j <= 3; j++)
                {
                    if (j == 0)
                    {
                        score[i, 0] = 106000 + i;           //指定學號
                    }
                    else
                    {
                        sum += score[i, j];                 //三科成績已經由Rand()作好
                        grv[j, i].Value = string.Format("{0:#######}", score[i, j]);    //整數
                        if(score[i, j] < 60)
                        {
                            grv[j, i].Style.ForeColor = Color.Red;
                        }
                    }
                }

                score[i, 4] = (int)(sum);
                grv[4, i].Value = score[i, 4].ToString();                               //sum;
                grv[0, i].Value = score[i, 0];                                          //學號
             
            }
            this.grv.AutoResizeColumns();             //自動調整欄寬
            for (i = 0; i <= r - 1; i++)        //各個Cell水平置中
            {
                for (j = 0; j < c; j++)
                {
                    grv.Columns[j].SortMode = DataGridViewColumnSortMode.NotSortable;                         //關閉欄位自動排序功能
                    grv.Columns[j].DefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;      //水平置中 1-8
                }
            }
        }

        private void btn2_Click(object sender, System.EventArgs e)
        {
            //已統計
            IsStatistics = true;

            //計算個人平均
            StdAvg();

            //計算各個科目平均
            CourseAvg();

            //排名            
            Rank();
            
            //不及格科目數
            Failed();

            //文字/背景顏色
            ChangeColor();

            //調整欄寬
            grv.AutoResizeColumns();
            
        }

        private void Grv_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show("第" + grv.CurrentRow.Index + "列,第"+e.ColumnIndex+"欄");  //for test

            if (IsStatistics && e.RowIndex == 0) 
            {
                if (sortFlag[e.ColumnIndex] == 1 || sortFlag[e.ColumnIndex] == -1)
                {
                    sortFlag = new int[] { -1, -1, -1, -1, -1, -1, -1, -1 };
                    sortFlag[e.ColumnIndex] = 0;
                    SortAsc(e.ColumnIndex);
                }
                else if (sortFlag[e.ColumnIndex] == 0)
                {
                    sortFlag = new int[] { -1, -1, -1, -1, -1, -1, -1, -1 };
                    sortFlag[e.ColumnIndex] = 1;
                    SortDesc(e.ColumnIndex);
                }
            }
        }

        public void SortAsc(int col) //遞增排序
        {
            IList<IList<float>> score_List = new List<IList<float>>();
            for (int row = 1; row < score.GetUpperBound(0); row++) 
            {
                score_List.Add(TFunction.GetRow(score, row).ToArray()); 
            }
            score_List = score_List.OrderBy(x => x[col]).ToList();
            for (int i = 1; i < r - 1; i++) 
            {
                for (int j = 0; j < c; j++)
                {
                    score[i, j] = score_List[i - 1][j];
                    if (j == 5) 
                        grv[j, i].Value = string.Format("{0:######.0}", score[i, j]);
                    else
                        grv[j, i].Value = string.Format("{0:######0}", score[i, j]);

                    //調整文字顏色
                    if (j < 6 && score_List[i - 1][j] < 60) 
                    {
                        grv[j, i].Style.ForeColor = Color.Red;
                    }
                    else
                    {
                        if (j == 0)
                        {
                            grv[j, i].Style.ForeColor = Color.Green;
                        }
                        else
                        {
                            grv[j, i].Style.ForeColor = Color.Black;
                        }
                    }
                }
            }
        }
        public void SortDesc(int col) //遞減排序 ---> 必定已ASC排序
        {
            IList<IList<float>> score_List = new List<IList<float>>();
            for (int row = 1; row < score.GetUpperBound(0); row++)
            {
                score_List.Add(TFunction.GetRow(score, row).ToArray());
            }
            score_List = score_List.Reverse().ToList();
            for (int i = 1; i < r - 1; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    score[i, j] = score_List[i - 1][j];
                    if (j == 5)
                        grv[j, i].Value = string.Format("{0:######.0}", score[i, j]);
                    else
                        grv[j, i].Value = string.Format("{0:######0}", score[i, j]);

                    //調整文字顏色
                    if (j < 6 && score_List[i - 1][j] < 60)
                    {
                        grv[j, i].Style.ForeColor = Color.Red;
                    }
                    else
                    {
                        if (j == 0)
                        {
                            grv[j, i].Style.ForeColor = Color.Green;
                        }
                        else
                        {
                            grv[j, i].Style.ForeColor = Color.Black;
                        }
                    }
                }
            }
        }

        public void Rand()  //取亂數到 score 三科成績
        {
            int i, j;
            Random rm = new Random();
            int count = 0;
            for (i = 1; i <= n; i++) 
            {
                count = 0;
                for (j = 1; j <= 3; j++)
                {
                      score[i, j] = rm.Next(40, 101); ;   //將成績置入score[,]
                    if (score[i, j] < 60) count++; //不及格科目計算
                }

                score[i, 7] = count;
            }
           
        }

        public void StdAvg() //個人平均
        {
            for (int row = 1; row <= n; row++)
            {
                score[row, 5] = score[row, 4] / 3f;
                grv[5, row].Value = string.Format("{0:####.0}", score[row, 5]);
                if (score[row, 5] < 60)
                {
                    grv[5, row].Style.ForeColor = Color.Red;
                }
            }
        }
        public void CourseAvg() //科平均
        {
            List<float[]> score_col = new List<float[]>(score.GetUpperBound(1)); //取col(每科成績列表)
            for (int col = 0; col < score.GetUpperBound(1); col++)
            {
                score_col.Add(TFunction.GetCol(score, col).Skip(1).Take(n).ToArray()); //.Skip(1)略過表頭.Take(n)略過科平均的空值
            }

            for (int col = 1; col <= 5; col++)
            {
                score[r - 1, col] = score_col[col].ToArray().Average();
                grv[col, r - 1].Value = string.Format("{0:####.0}", score[r - 1, col]);
                if (score[r - 1, col] < 60)
                {
                    grv[col, r - 1].Style.ForeColor = Color.Red;
                }
            }

            //所有總分
            score[r - 1, 4] = score_col[4].ToArray().Sum();
            grv[4, r - 1].Value = string.Format("{0:######}", score[r - 1, 4]);
        }
        public void Rank()
        {
            IList<IList<float>> score_iList = new List<IList<float>>(); // {[學號,總分]...}
            Dictionary<float, float> rank = new Dictionary<float, float>(); // {['學號',排名]...}

            for (int i = 1; i <= n; i++)
            {
                score_iList.Add(new float[] { score[i, 0], score[i, 4] });
            }

            List<IList<float>> score_sort = score_iList.OrderByDescending(x => x[1]).ToList(); //用總分排序

            for (int i = 0; i < n; i++) // 新增至字典{['學號',排名]...}
            {
                if (i > 1 && score_sort[i - 1][1] == score_sort[i][1]) //判斷總分相同 ---> 名次相同
                {
                    rank.Add(score_sort[i][0], rank[score_sort[i - 1][0]]);
                }
                else
                {
                    rank.Add(score_sort[i][0], i + 1);
                }
            }

            for (int row = 1; row <= n; row++)
            {
                score[row, 6] = rank[score[row, 0]];
                grv[6, row].Value = string.Format("{0:######}", score[row, 6]);
            }
        }

        public void Failed() //不及格科目(已在Rand()計算)
        {
            for (int col = 1; col <= n; col++)
            {
                grv[7, col].Value = string.Format("{0:#####0}", score[col, 7]);
            }
        }
        public void ChangeColor()
        {
            grv[5, r - 1].Style.BackColor = Color.Aqua;
        }
        private void btn3_Click(object sender, System.EventArgs e)
        {
            this.Dispose();   //只有Form1 程式結束
        }


    }
    static class TFunction //通用函式
    {
        //取得2維陣列第 n row 之一維陣列
        public static T[] GetRow<T>(T[,] matrix, int rowNumber)
        {
            var a = Enumerable.Range(0, matrix.GetUpperBound(1) + 1)
                    .Select(x => matrix[rowNumber, x])
                    .ToArray();
            return a;
        }
        //取得2維陣列第 n col 之一維陣列
        public static T[] GetCol<T>(T[,] matrix, int colNumber)
        {
            var a = Enumerable.Range(0, matrix.GetUpperBound(0) + 1)
                    .Select(x => matrix[x, colNumber])
                    .ToArray();
            return a;
        }
    }
} 
