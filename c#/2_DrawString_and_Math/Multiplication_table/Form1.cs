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
 * @Date: 2020-2-6
 * @Last Modified by: Jessie Huang
 * @Last Modified time: 2020-2-6
 */
namespace Multiplication_table
{
    public partial class Form1 : Form
    {
        Label[] labels = new Label[81];
        static int x = 0, y = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.SkyBlue;
            //生成label
            for (int i = 0; i < 81; i++)
            {
                labels[i] = new Label();
                labels[i].AutoSize = true;
                labels[i].Location = new Point(y * panel1.Width / 9, x * 40);
                labels[i].Name = "label" + (i + 1).ToString();

                int a = i / 9 + 1;
                int b = (((i + 1) % 9 == 0) ? 9 : (i + 1) % 9);
                int mul = a * b;
                string sol = (mul / 10 > 0) ? mul.ToString() : "  " + mul.ToString();
                labels[i].Text = a + " x " + b + " = " + sol;
                labels[i].BackColor = Color.LemonChiffon;
                labels[i].BorderStyle = BorderStyle.Fixed3D;
                panel1.Controls.Add(labels[i]);
                y++;
                if (i % 9 == 8)
                {
                    x++;
                    y = 0;
                }
            }
        }

        private void btn_show_Click(object sender, EventArgs e)
        {
            panel1.Show();
        }

        private void btn_hide_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 81; i++)
                labels[i].Dispose();                        
            //**以上迴圈替代下式
            //panel1.Hide();
        }
    }
}
