using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*
 * @Author: Jessie Huang
 * @Date: 2020-2-10
 * @Last Modified by: Jessie Huang
 * @Last Modified time: 2020-2-10
 */
namespace Draw_String
{
    public partial class Form1 : Form
    {
        
        static List<string> Q1 = new List<string> { "１\n", "２ ２\n", "３ ３ ３\n", "４ ４ ４ ４\n", "５ ５ ５ ５ ５" };
        static List<string> Q2 = new List<string> { "１\n", "１ ２\n", "１ ２ ３\n", "１ ２ ３ ４\n", "１ ２ ３ ４ ５" };
        static List<string> Q3 = new List<string> { "Ａ\n", "Ｂ Ｂ\n", "Ｃ Ｃ Ｃ\n", "Ｄ Ｄ Ｄ Ｄ\n", "Ｅ Ｅ Ｅ Ｅ Ｅ" };
        static List<string> Q4 = new List<string> { "Ｅ Ｅ Ｅ Ｅ Ｅ\n", "Ｄ Ｄ Ｄ Ｄ\n", "Ｃ Ｃ Ｃ\n", "Ｂ Ｂ\n", "Ａ" };
        static List<string> Q5 = new List<string> { "Ａ\n", "Ａ Ｂ\n", "Ａ Ｂ Ｃ\n", "Ａ Ｂ Ｃ Ｄ\n", "Ａ Ｂ Ｃ Ｄ Ｅ" };
        static List<string> Q6 = new List<string> { "Ａ Ｂ Ｃ Ｄ Ｅ\n", "Ａ Ｂ Ｃ Ｄ\n", "Ａ Ｂ Ｃ\n", "Ａ Ｂ\n", "Ａ" };
        
        //**增加宣告 Graphics、GraphicsA6 ... 物件, 使其為區域變數，方便其他事件使用
        Graphics Graphics1,  Graphics2, Graphics3;
        Graphics GraphicsA1, GraphicsA2, GraphicsA3, GraphicsA4, GraphicsA5, GraphicsA6;
        Rectangle rectA1, rectA2, rectA3, rectQ1, rectQ2;
        string[] text;
        Font font1;
        StringFormat stringFormatCenter = new StringFormat();
        StringFormat stringFormatNear = new StringFormat();     //靠左對齊
        StringFormat stringFormatFar = new StringFormat();      //靠右對齊

        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            //hide test labels
            label1.Dispose();
            label2.Dispose();
            label3.Dispose();
            label4.Dispose();
            label5.Dispose();

            //set title
            label_description.Text = "※試做下列6題，每題各有靠左、置中、靠右，以Graphics.Drawing(string, Font, Brush, PointF)顯示於各button下方";
            
            Paint1();       //**增
        }
       
        private void Paint1()               //**增
        {
            text = new string[6] {
                String.Join("", Q1),
                String.Join("", Q2),
                String.Join("", Q3),
                String.Join("", Q4),
                String.Join("", Q5),
                String.Join("", Q6) };

            //垂直置中對齊
            StringFormat stringFormatCenter = new StringFormat();
            stringFormatCenter.Alignment = StringAlignment.Center;
            stringFormatCenter.LineAlignment = StringAlignment.Center;

            //靠左對齊
            StringFormat stringFormatNear = new StringFormat();
            stringFormatNear.Alignment = StringAlignment.Near;
            stringFormatNear.LineAlignment = StringAlignment.Center;

            //靠右對齊
            StringFormat stringFormatFar = new StringFormat();
            stringFormatFar.Alignment = StringAlignment.Far;
            stringFormatFar.LineAlignment = StringAlignment.Center;

            Rectangle rectQ1 = new Rectangle(45, 10, 110, 110);
            Rectangle rectQ2 = new Rectangle(270, 10, 110, 110);

            font1 = new Font("微軟正黑體", 12, FontStyle.Regular, GraphicsUnit.Point);               //**各個button_Q1,Q2....使用

            //using (font1 = new Font("微軟正黑體", 12, FontStyle.Regular, GraphicsUnit.Point))      //**有上式，本式可免，
            {
                ///<summary>
                ///繪製答案
                /// </summary>
                GraphicsA1 = panel_A1.CreateGraphics();
                GraphicsA2 = panel_A2.CreateGraphics();
                GraphicsA3 = panel_A3.CreateGraphics();
                GraphicsA4 = panel_A4.CreateGraphics();
                GraphicsA5 = panel_A5.CreateGraphics();
                GraphicsA6 = panel_A6.CreateGraphics();
                rectA1 = new Rectangle(50, 35, 110, 110);
                rectA2 = new Rectangle(50, 175, 110, 110);
                rectA3 = new Rectangle(50, 305, 110, 110);
                
            }

        }

        private void button1_Click(object sender, EventArgs e)      //**增設
        {
            button_Q1_Click(sender, e);
            button_Q2_Click(sender, e);
            button_Q3_Click(sender, e);
            button_Q4_Click(sender, e);
            button_Q5_Click(sender, e);
            button_Q6_Click(sender, e);
        }

        private void button_Q1_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A1.Show();
            //button_clear.Refresh();
        }

        private void button_Q2_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A2.Show();
            //button_clear.Refresh();
        }

        private void button_Q3_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A3.Show();
            //utton_clear.Refresh();
        }

        private void button_Q4_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A4.Show();
            //button_clear.Refresh();
        }

        private void button_Q5_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A5.Show();
            //button_clear.Refresh();
        }

        private void button_Q6_Click(object sender, EventArgs e)
        {
            //**改button執行繪圖
            GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA1, stringFormatNear);
            GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA2, stringFormatCenter);
            GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA3, stringFormatFar);
            //panel_A6.Show();
            //button_clear.Refresh();
        }

        private void button_clear_Click(object sender, EventArgs e)      //**使用panel背景色刷新   
        {
            GraphicsA1.Clear(panel_A1.BackColor);                        //以原panel_A1的背景色刷新
            GraphicsA2.Clear(panel_A2.BackColor);
            GraphicsA3.Clear(panel_A2.BackColor);
            GraphicsA4.Clear(panel_A2.BackColor);
            GraphicsA5.Clear(panel_A2.BackColor);
            GraphicsA6.Clear(panel_A2.BackColor);
            /*
            panel_A1.Hide();
            panel_A2.Hide();
            panel_A3.Hide();
            panel_A4.Hide();
            panel_A5.Hide();
            panel_A6.Hide();
            */
        }

        //**原設定事件暫不使用
        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            text = new string[6] {
                String.Join("", Q1),
                String.Join("", Q2),
                String.Join("", Q3),
                String.Join("", Q4),
                String.Join("", Q5),
                String.Join("", Q6) };

            //垂直置中對齊
            stringFormatCenter.Alignment = StringAlignment.Center;
            stringFormatCenter.LineAlignment = StringAlignment.Center;

            //靠左對齊
            stringFormatNear.Alignment = StringAlignment.Near;
            stringFormatNear.LineAlignment = StringAlignment.Center;

            //靠右對齊
            stringFormatFar.Alignment = StringAlignment.Far;
            stringFormatFar.LineAlignment = StringAlignment.Center;

            using (Font font1 = new Font("微軟正黑體", 12, FontStyle.Regular, GraphicsUnit.Point))
            {
                ///<summary>
                ///繪製題目
                /// </summary>
                Graphics1 = panel_Q1_Q2.CreateGraphics();
                Graphics2 = panel_Q3_Q4.CreateGraphics();
                Graphics3 = panel_Q5_Q6.CreateGraphics();
                rectQ1 = new Rectangle(45, 10, 110, 110);
                rectQ2 = new Rectangle(270, 10, 110, 110);

                // Draw the text and the surrounding rectangle.
                // DrawString(String, Font, Brush, RectangleF, StringFormat)
                Graphics1.DrawString(text[0], font1, Brushes.Blue, rectQ1, stringFormatCenter);
                Graphics1.DrawString(text[1], font1, Brushes.Blue, rectQ2, stringFormatNear);
                Graphics2.DrawString(text[2], font1, Brushes.Blue, rectQ1, stringFormatFar);
                Graphics2.DrawString(text[3], font1, Brushes.Blue, rectQ2, stringFormatFar);
                Graphics3.DrawString(text[4], font1, Brushes.Blue, rectQ1, stringFormatFar);
                Graphics3.DrawString(text[5], font1, Brushes.Blue, rectQ2, stringFormatFar);

                //顯示基準外框線 
                //Graphics1.DrawRectangle(Pens.Black, rectQ1);
                //Graphics2.DrawRectangle(Pens.Black, rectQ1);
                //Graphics3.DrawRectangle(Pens.Black, rectQ1);
                //Graphics1.DrawRectangle(Pens.Black, rectQ2);
                //Graphics2.DrawRectangle(Pens.Black, rectQ2);
                //Graphics3.DrawRectangle(Pens.Black, rectQ2);


                ///<summary>
                ///繪製答案
                /// </summary>
                GraphicsA1 = panel_A1.CreateGraphics();
                GraphicsA2 = panel_A2.CreateGraphics();
                GraphicsA3 = panel_A3.CreateGraphics();
                GraphicsA4 = panel_A4.CreateGraphics();
                GraphicsA5 = panel_A5.CreateGraphics();
                GraphicsA6 = panel_A6.CreateGraphics();
                rectA1 = new Rectangle(50, 35, 110, 110);
                rectA2 = new Rectangle(50, 175, 110, 110);
                rectA3 = new Rectangle(50, 305, 110, 110);
                //**以上段替代下段，將GraphicsA、rect作區域變數，方便其他事件運用(清除button_clear)

                /////<summary>
                /////繪製答案
                ///// </summary>
                //Graphics GraphicsA1 = panel_A1.CreateGraphics();
                //Graphics GraphicsA2 = panel_A2.CreateGraphics();
                //Graphics GraphicsA3 = panel_A3.CreateGraphics();
                //Graphics GraphicsA4 = panel_A4.CreateGraphics();
                //Graphics GraphicsA5 = panel_A5.CreateGraphics();
                //Graphics GraphicsA6 = panel_A6.CreateGraphics();
                //Rectangle rectA1 = new Rectangle(50, 35, 110, 110);
                //Rectangle rectA2 = new Rectangle(50, 175, 110, 110);
                //Rectangle rectA3 = new Rectangle(50, 305, 110, 110);

                /*
                //題一
                GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA1.DrawString(text[0], font1, Brushes.Blue, rectA3, stringFormatFar);

                //題二
                GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA2.DrawString(text[1], font1, Brushes.Blue, rectA3, stringFormatFar);

                //題三
                GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA3.DrawString(text[2], font1, Brushes.Blue, rectA3, stringFormatFar);
                
                //題四
                GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA4.DrawString(text[3], font1, Brushes.Blue, rectA3, stringFormatFar);

                //題五
                GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA5.DrawString(text[4], font1, Brushes.Blue, rectA3, stringFormatFar);

                //題六
                GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA1, stringFormatNear);
                GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA2, stringFormatCenter);
                GraphicsA6.DrawString(text[5], font1, Brushes.Blue, rectA3, stringFormatFar);
                */
            }
        }

    }
}
