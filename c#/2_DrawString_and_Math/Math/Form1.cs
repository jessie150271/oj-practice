using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

/*
 * @Author: Jessie Huang
 * @Date: 2020-2-5
 * @Last Modified by: Jessie Huang
 * @Last Modified time: 2020-2-6
 */
namespace Math
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //繪製圓角矩形Label
            DrawRoundRect(new Label[] { No1, No2, No3, No4, No5 });

            numericUpDown1.Value = 50;                          //**原10
            Question.Q1 = numericUpDown1.Value.ToString();
            Question.Q2 = numericUpDown1.Value.ToString();
            QuestionBox.Text = Question.Q1;
            showSolutions();
        }
        private void DrawRoundRect(params Label[] labels)
        {
            foreach (Label label in labels)
            {
                float X = (float)(label.Width);
                float Y = (float)(label.Height);
                PointF[] points =
                    {
                    new PointF(2,0),
                    new PointF(X-2,0),
                    new PointF(X,2),
                    new PointF(X,Y-2),
                    new PointF(X-2,Y),
                    new PointF(2,Y),
                    new PointF(0,Y-2),
                    new PointF(0,2),
                };
                GraphicsPath path = new GraphicsPath();
                path.AddLines(points);
                label.Region = new Region(path);
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            Question.Q1 = numericUpDown1.Value.ToString();
            Question.Q2 = numericUpDown1.Value.ToString();
            if (radioMath1.Checked)
            {
                QuestionBox.Text = Question.Q1;
            }

            else if (radioMath2.Checked)
            {
                QuestionBox.Text = Question.Q2;
            }
            showSolutions();
        }

        private void radioMath1_CheckedChanged(object sender, EventArgs e)
        {
            numericUpDown1.Value = 50;                          //**增
            Question.Q1 = numericUpDown1.Value.ToString();      //**增
            QuestionBox.Text = Question.Q1;
            showSolutions();
        }

        private void radioMath2_CheckedChanged(object sender, EventArgs e)
        {
            numericUpDown1.Value = 10;                          //**增
            Question.Q2 = numericUpDown1.Value.ToString();      //**增
            QuestionBox.Text = Question.Q2;
            showSolutions();
        }

        private void showSolutions()
        {
            int n = Convert.ToInt32(numericUpDown1.Value);
            if (radioMath1.Checked)
            {
                //For
                Ans1_1.Text = Math1_Solution_For.No1(n).ToString();
                Ans1_2.Text = Math1_Solution_For.No2(n).ToString();
                Ans1_3.Text = Math1_Solution_For.No3(n).ToString();
                Ans1_4.Text = Math1_Solution_For.No4(n).ToString("f7");
                Ans1_5.Text = Math1_Solution_For.No5(n).ToString();

                //Recursive
                Ans2_1.Text = Math1_Solution_Recursive.No1(n).ToString();
                Ans2_2.Text = Math1_Solution_Recursive.No2(n).ToString();
                Ans2_3.Text = Math1_Solution_Recursive.No3(n).ToString();
                Ans2_4.Text = Math1_Solution_Recursive.No4(n).ToString("f7");
                Ans2_5.Text = Math1_Solution_Recursive.No5(n).ToString();
            }

            else if (radioMath2.Checked)
            {
                //For
                Ans1_1.Text = Math2_Solution_For.No1(n).ToString("f7");
                Ans1_2.Text = Math2_Solution_For.No2(n).ToString("f7");
                Ans1_3.Text = (n > 20) ? "計算結果溢位" : Math2_Solution_For.No3(n).ToString();
                Ans1_4.Text = Math2_Solution_For.No4(n).ToString("f7");
                Ans1_5.Text = Math2_Solution_For.No5(n).ToString("f7");

                //Recursive
                Ans2_1.Text = Math2_Solution_Recursive.No1(n).ToString("f7");
                Ans2_2.Text = Math2_Solution_Recursive.No2(n).ToString("f7");
                Ans2_3.Text = (n > 20) ? "計算結果溢位" : Math2_Solution_Recursive.No3(n).ToString();
                Ans2_4.Text = Math2_Solution_Recursive.No4(n).ToString("f7");
                Ans2_5.Text = Math2_Solution_Recursive.No5(n).ToString("f7");
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }

    class Question
    {
        static string Math1 = "";
        public static string Q1
        {
            get { return Math1; }
            set
            {
                Math1 =
                "(1)1+2+3+4+5+6+7......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(2)1+3+5+7+9+11......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(3)2+4+6+8+10+12......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(4)1+1/(1+2)+1/(1+2+3)+1/(1+2+3+4)+1/(1+2+3+4+5)......\n" +
                "   當 項數(n) = " + value + " 值為多少?(解答請顯示到小數以下第7位)\n\n\n" +
                "(5)1-2+3-4+5-6+7......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n";
            }
        }
        static string Math2 = "";
        public static string Q2
        {
            get { return Math2; }
            set
            {
                Math2 =
                "(1)1+1/2+1/3+1/4+1/5+1/6+1/7......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(2)1-1/2+1/3-1/4+1/5-1/6+1/7-1/8......\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(3)1+2!+3!+4!+...+n!\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "(4)(1)+(1+1/2)+(1+1/2+1/3)+(1+1/2+1/3+1/4)+(1+1/2+1/3+1/4+1/5)......\n" +
                "   當 項數(n) = " + value + " 值為多少?(解答請顯示到小數以下第7位)\n\n\n" +
                "(5)1+1/2+2/3+3/4+4/5...+(n-1)/n\n" +
                "   當 項數(n) = " + value + " 值為多少?\n\n\n" +
                "※第1、2、4、5題解答，請顯示到小數以下第7位。";
            }
        }
    }
    class MathFunc
    {
        /// <summary>
        /// 實作大數階乘
        /// </summary>
        /// <param term="n"></param>
        /// <returns></returns>
        public static long factorial(int n)
        {
            long ret = 1;
            
            for (int i = 1; i <= n; i++)
            {
                ret *= i;
            }
            return ret;
        }

        /*      似乎沒有用到
        public static string add(int n)
        {
            string ret = "";

            for (int i = 1; i <= n; i++)
            {

            }
            return ret;
        }
        */
    }

    class Math1_Solution_For
    {
        public static int No1(int n)
        {
            int ret = 0;
            for(int i = 1; i <= n; i++)
            {
                ret += i;
            }
            return ret;
        }
        public static int No2(int n)
        {
            //f(n) = 2n-1
            int ret = 0;
            for(int i = 1; i <= n; i++)
            {
                ret += 2 * i - 1;
            }
            return ret;
        }
        public static int No3(int n)
        {
            //f(n) = 2n
            int ret = 0;
            for (int i = 1; i <= n; i++)
            {
                ret += 2 * i;
            }
            return ret;
        }
        public static double No4(int n)
        {
            //f(n) = 1/((1+n)*n/2)
            double ret = 0;
            for(int i = 1; i <= n; i++)
            {
                ret += 1 / (double)((1 + i) * i / 2);
            }
            return ret;
        }
        public static int No5(int n)
        {
            //f(n) = (n % 2 == 0)? (-1) * n : n
            int ret = 0;
            for(int i = 1; i <= n; i++)
            {
                ret += ((i % 2 == 0) ? (-1) * i : i);
            }
            return ret;
        }
    }

    class Math1_Solution_Recursive
    {
        public static int No1(int n)
        {
            return (n == 1) ? 1 : (n + No1(n - 1));
        }
        public static int No2(int n)
        {
            //f(n) = 2n-1
            return (n == 1) ? 1 : (2 * n - 1 + No2(n - 1));
        }
        public static int No3(int n)
        {
            //f(n) = 2n
            return (n == 1) ? 2 : (2 * n + No3(n - 1));
        }
        public static double No4(int n)
        {
            //f(n) = 1/((1+n)*n/2)
            return (n == 1) ? 1 : (1 / (double)((1 + n) * n / 2) + No4(n - 1));
        }
        public static int No5(int n)
        {
            //f(n) = (n % 2 == 0)? (-1) * n : n
            return (n == 1) ? 1 : (n % 2 == 0) ? (-1) * n + No5(n - 1) : n + No5(n - 1);
        }
    }

    class Math2_Solution_For
    {
        public static double No1(int n)
        {
            double ret = 0;
            for(int i = 1; i <= n; i++)
            {
                ret += 1.0 / i;
            }
            return ret;
        }
        public static double No2(int n)
        {
            double ret = 0;
            for (int i = 1; i <= n; i++)
            {
                ret += (i % 2 == 0) ? (-1.0) / i : 1.0 / i;
            }
            return ret;
        }
        public static long No3(int n)
        {
            long ret = 0;
            for (int i = 1; i <= n; i++)
            {
                ret += MathFunc.factorial(i);
            }
            return ret;
        }
        public static double No4(int n)
        {
            double ret = 0;
            for (int i = 1; i <= n; i++)
            {
                ret += No1(i);
            }
            return ret;
        }
        public static double No5(int n)
        {
            double ret = 1;
            for (int i = 1; i < n; i++)
            {
                ret += i / (i + 1.0);
            }
            return ret;
        }
    }

    class Math2_Solution_Recursive
    {
        public static double No1(int n)
        {
            return (n == 1) ? 1 : 1.0 / n + No1(n - 1);
        }
        public static double No2(int n)
        {
            return (n == 1) ? 1 : (n % 2 == 0) ? (-1.0) / n + No2(n - 1) : 1.0 / n + No2(n - 1);
        }
        public static long No3(int n)
        {
            return (n == 1) ? 1 : MathFunc.factorial(n) + No3(n - 1);
        }
        public static double No4(int n)
        {
            return (n == 1) ? 1 : No1(n) + No4(n - 1);
        }
        public static double No5(int n)
        {
            return (n == 1) ? 1 : (n - 1.0) / n + No5(n - 1);
        }
    }
}
