using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Text.RegularExpressions;

/* @Title: CsvToGrid
 * @Description: 將Csv檔轉成DataGridView排序再另存新檔(或轉檔)
 * @Author: Jessie Huang
 * @Date: 2020-03-10
 * @Last Modified by: Jessie Huang
 * @Last Modified time: 2020-03-16
 */
namespace CsvToGrid
{
    public partial class Form1 : Form
    {
        //初始化資料處理類別
        private DataHelper dataHelper;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //初始化物件
            dataHelper = new DataHelper();
            //初始化下拉選單
            dataHelper.SetDropDownList(comboBox1);
            //初始化UI介面
            DisplayChange(0, 0);
        }

        private void pictureBox1_Click(object sender, EventArgs e) //選檔、讀檔至listBox
        {
            dataHelper.Read();
            if (dataHelper.FileReader.Count > 0)
            {
                dataHelper.Display(listBox1);
                label1.Text = "更換csv檔";
                //未嘗試動態生成class，實作牽涉到Reflection Emit、MSIL op
                //若上傳其他csv檔將無法排序數字/日期欄位(若欄位名稱與此題相同則可以 --> "月薪" "出生日")
                DisplayChange(1, 0);
            }
        }

        private void button1_Click(object sender, EventArgs e) //將listBox資料轉成DataGridView
        {
            dataHelper.Format(dgv);
            DisplayChange(0, 1);
        }

        public void button2_Click(object sender, EventArgs e) //匯出檔案
        {
            dataHelper.SaveCsv(dgv,comboBox1.SelectedItem.ToString());
        }
        private void DisplayChange(int a, int b)
        {
            switch (a)
            {
                case 0:
                    button1.Hide();
                    listBox1.Hide();
                    break;
                case 1:
                    button1.Show();
                    listBox1.Show();
                    break;
                default:
                    break;
            }
            switch (b)
            {
                case 0:
                    button2.Hide();
                    comboBox1.Hide();
                    break;
                case 1:
                    button2.Show();
                    comboBox1.Show();
                    break;
                default:
                    break;
            }
        }
    }

    /// <summary>
    /// 資料處理類別
    /// </summary>
    internal class DataHelper
    {
        #region prop
        /// <summary>
        /// constructor
        /// </summary>
        internal DataHelper()
        {
            FileReader = new List<string>();
            DataHeader = new List<string>();
            DataList = new List<List<string>>();
            sc = new Dictionary<string, char>();
            sc.Add("逗號", ',');
            sc.Add("分號", ';');
            sc.Add("空白", ' ');
            sc.Add("TAB", '\t');
            sc.Add("冒號", ':');
        }        
        /// <summary>
        /// 符號字典
        /// </summary>
        private Dictionary<string, char> sc { get; }
        /// <summary>
        /// 文件每行資料
        /// </summary>
        public List<string> FileReader { get; }
        /// <summary>
        /// 資料標頭
        /// </summary>
        public List<string> DataHeader { get; }
        /// <summary>
        /// 資料內容
        /// </summary>
        public List<List<string>> DataList { get; }
        /// <summary>
        /// 視圖綁定表格
        /// </summary>
        private DataTable dt;
        #endregion

        #region method
        /// <summary>
        /// 初始化下拉選單
        /// </summary>
        /// <param name="comboBox"></param>
        public void SetDropDownList(ComboBox comboBox)
        {
            comboBox.Items.AddRange(sc.Keys.ToArray());
            comboBox.SelectedIndex = 0;
        }
        /// <summary>
        /// 讀檔
        /// </summary>
        public void Read()
        {
            //取得當前專案路徑
            DirectoryInfo dir = new DirectoryInfo(Directory.GetCurrentDirectory());
            dir = dir.Parent.Parent.Parent;

            string filePath = dir.FullName;
            
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = filePath;
            openFileDialog.RestoreDirectory = true;
            //自定義檔案篩選條件 以"|"分隔名稱、檔案類型、選項群組 Ex:"txt files (*.txt)|*.txt|All files (*.*)|*.*"
            openFileDialog.Filter = "Excel files (*.csv)|*.csv";
            //預設選擇的Filter選項 第一項為[1]
            openFileDialog.FilterIndex = 1;

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                //初始化容器
                FileReader.Clear();
                DataList.Clear();
                DataHeader.Clear();
                dt = new DataTable("csvTable");
                //讀取檔案內容
                Stream fileStream = openFileDialog.OpenFile();
                StreamReader reader = new StreamReader(fileStream, Encoding.Default); //.Net預設為Unicode，ANSI預設多為Big5，所以直接讀中文內容會變亂碼，必須轉碼 -> Encoding.Default

                string container = "";
                while (reader.Peek() > 0)
                {
                    container = reader.ReadLine();
                    if (!string.IsNullOrEmpty(container))
                    { 
                        FileReader.Add(container);
                    }
                }
                /** for test **/
                //filePath = openFileDialog.FileName;
                //MessageBox.Show(filePath, "Current path", MessageBoxButtons.OK);
            }
            openFileDialog.Dispose();
        }
        /// <summary>
        /// 匯入至listBox
        /// </summary>
        /// <param name="listBox">ListBox obj</param>
        public void Display(ListBox listBox) 
        {
            listBox.Items.Clear();
            //-----Begin-----
            listBox.BeginUpdate();
            FileReader.ForEach(x =>
            {
                //將資料欄匯入dataList暫存 List<T>  T = List<string>
                DataList.Add(x.Split(',').ToList());
                //將資料列匯入listBox
                listBox.Items.Add(x);
            });
            DataHeader.AddRange(DataList[0]);
            DataList.RemoveAt(0);
            listBox.EndUpdate();
            listBox.Refresh();
            //-----End-----
        }
        /// <summary>
        /// 初始化DataGridView，將DataTable dt綁定DataSource
        /// </summary>
        /// <param name="dgv">DataGridView obj</param>
        public void Format(DataGridView dgv) 
        {
            CreateDataTable();

            //初始化DataGridView
            dgv.DataSource = null;
            dgv.Font = new Font("微軟正黑體", 12, FontStyle.Regular);
            dgv.BackgroundColor = SystemColors.Control;
            dgv.EditMode = DataGridViewEditMode.EditProgrammatically; //關閉編輯
            dgv.DataSource = dt;
            dgv.Refresh();
            dgv.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        }
        /// <summary>
        /// 初始化資料綁定表格
        /// </summary>
        private void CreateDataTable()
        {
            DataHeader.ForEach(x =>
            {
                try
                {
                    //轉型判斷是否為數字
                    double.Parse(DataList[0][DataHeader.IndexOf(x)]);
                    dt.Columns.Add(x, typeof(double)); 
                }
                catch
                {
                    //正規判斷日否為日期格式
                    string pattern = @"^(19|20)\d\d[\-\/\\.](0?[1-9]|1[012])[\-\/\\.](0?[1-9]|[12][0-9]|3[01])$";
                    Regex regex = new Regex(pattern);
                    if (regex.IsMatch(DataList[0][DataHeader.IndexOf(x)]))
                    {
                        dt.Columns.Add(x, typeof(DateTime));
                    }
                    else
                    {
                        dt.Columns.Add(x, typeof(string));
                        dt.Columns[x].MaxLength = 100;
                    }
                }

                dt.Columns[x].AllowDBNull = true;
            });
            DataList.ForEach(y =>
            {
                DataRow row = dt.NewRow();
                int i = 0;
                DataHeader.ForEach(x =>
                {
                    row[x] = y[i++];
                });
                dt.Rows.Add(row);
            });
        }
        /// <summary>
        /// 存csv檔
        /// </summary>
        /// <param name="dgv">DataGridView obj</param>
        /// <param name="item">分隔符號</param>
        public void SaveCsv(DataGridView dgv, string item)
        {
            char delimiter = sc[item];
            if (dgv.Rows.Count > 0)
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "CSV (*.csv)|*.csv";
                saveFileDialog.FileName = "Output.csv";
                bool fileError = false;
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    if (File.Exists(saveFileDialog.FileName))
                    {
                        try
                        {
                            File.Delete(saveFileDialog.FileName);
                        }
                        catch (IOException ex)
                        {
                            fileError = true;
                            MessageBox.Show("存檔失敗!\nError : " + ex.Message, "Info", MessageBoxButtons.OK);
                        }
                    }
                    if (!fileError)
                    {
                        try
                        {
                            int columnCount = dgv.Columns.Count;
                            string columnNames = "";
                            string[] outputCsv = new string[dgv.Rows.Count + 1];
                            for (int i = 0; i < columnCount; i++)
                            {
                                columnNames += dgv.Columns[i].HeaderText.ToString() + delimiter;
                            }
                            outputCsv[0] += columnNames.Substring(0, columnNames.Length-1);

                            for (int i = 1; i < dgv.Rows.Count; i++)
                            {
                                for (int j = 0; j < columnCount; j++)
                                {
                                    if (j == 3)
                                    {
                                        DateTime dateTime = DateTime.Parse(dgv.Rows[i - 1].Cells[j].Value.ToString());
                                        outputCsv[i] += dateTime.ToString("yyyy/M/d");
                                    }
                                    else outputCsv[i] += dgv.Rows[i - 1].Cells[j].Value.ToString();
                                    if (j < columnCount - 1) outputCsv[i] += delimiter;
                                }
                            }
                            File.WriteAllLines(saveFileDialog.FileName, outputCsv, Encoding.UTF8);
                            MessageBox.Show("存檔成功!", "Info",MessageBoxButtons.OK);
                            string file = @"C:\Windows\explorer.exe";
                            string argument = @"/select, "+saveFileDialog.FileName;
                            System.Diagnostics.Process.Start(file, argument);
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show("Error :" + ex.Message, "Info", MessageBoxButtons.OK);
                        }
                    }
                }
            }
        }
        #endregion
    }





    /** 取得專案路徑方式 **/
    //string path =
    //            //System.AppDomain.CurrentDomain.BaseDirectory;
    //            Directory.GetCurrentDirectory();
    //            //System.Windows.Forms.Application.StartupPath;
    //MessageBox.Show(path);

    /** Accessing Form's Controls from another class method **/
    //  Button btn = Application.OpenForms["Form1"].Controls["button1"] as Button;
    //  btn.BackColor = Color.Black;
}
