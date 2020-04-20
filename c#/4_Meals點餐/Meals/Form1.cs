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
 * @Date: 2020-02-18
 * @Last Modified by: Jessie Huang
 * @Last Modified time: 2020-02-19
 * @Version: 1.0
 */
namespace Meals
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        struct Component //選項組件
        {
            public Component(CheckBox a, TextBox b, Label c, int d)
            {
                checkBox = a;
                textBox = b;
                label = c;
                price = d;
            }
            public CheckBox checkBox;
            public TextBox textBox;
            public Label label;
            public readonly int price;
        }
        private List<Component> options = new List<Component>(); //泛型容器


        private void Form1_Load(object sender, EventArgs e)
        {
            //初始化泛型容器內容
            options.AddRange(
                new Component[] {
                    new Component(checkBox1, textBox1, label1, 30),
                    new Component(checkBox2, textBox2, label2, 35),
                    new Component(checkBox3, textBox3, label3, 40),
                    new Component(checkBox4, textBox4, label4, 40),
                    new Component(checkBox5, textBox5, label5, 100),
                    new Component(checkBox6, textBox6, label6, 120),
                    new Component(checkBox7, textBox7, label7, 10)
                });
            //初始化組件事件
            InitializeEvent();

            //起始畫面設定
            label8.Text = "歡迎光臨！";
            ChangeOption7(false);
        }
        private void InitializeEvent()
        {
            //共用事件
            options.ForEach(item =>
            {
                //set textBox event : select all on click
                item.textBox.Click += delegate
                {
                    item.textBox.SelectAll();
                };

                //set textBox event : on text chenged
                item.textBox.TextChanged += delegate
                {
                    try
                    {
                        int input = int.Parse(item.textBox.Text); //test if text is integer ---> use int.Parse is easier then Convert.Int32()

                        if (input > 0 && input < 1000) 
                        {
                            //format input and set checkBox
                            item.checkBox.Checked = true;
                            item.textBox.Text = input.ToString();
                            item.textBox.Select(item.textBox.Text.Length,0);
                        }
                        else
                        {
                            if (item.checkBox.Name == "checkBox7" && item.checkBox.Checked) 
                            {
                                item.textBox.Text = "1";
                                item.textBox.SelectAll();
                            }
                            else
                            {
                                //trim 0 before input
                                item.checkBox.Checked = false;
                                item.textBox.Text = "0";
                                item.textBox.SelectAll();
                            }
                        }
                    }
                    catch (Exception)
                    {
                        //catch not integer input

                        if (item.checkBox.Name == "checkBox7" && item.checkBox.Checked)
                        {
                            item.textBox.Text = "1";
                            item.textBox.SelectAll();
                        }
                        else
                        {
                            item.checkBox.Checked = false;
                            item.textBox.Text = (item.textBox.Text == "") ? "" : "0";
                            item.textBox.SelectAll();
                        }
                    }
                };

                //set checkBox event : on checked changed
                item.checkBox.CheckedChanged += delegate
                {
                    item.textBox.Text = item.checkBox.Checked ? "1" : "0";

                    //for UX
                    //without this step, the courser will be on the left side
                    if (item.checkBox.Checked) 
                    {
                        item.textBox.Focus();
                        item.textBox.SelectAll();
                    }
                };
            });

            //內用設定
            checkBox7.Enabled = false;

            //listBox
            listBox1.Font = new Font("標楷體", 12);
            listBox1.ItemHeight = 20;

            listBox1.DrawMode = DrawMode.OwnerDrawFixed;
            listBox1.DrawItem += (object s, DrawItemEventArgs e) =>
            {
                ListBox list = (ListBox)s;
                if (e.Index > -1)
                {
                    //設定置中對齊
                    object item = list.Items[e.Index];
                    e.DrawBackground();
                    e.DrawFocusRectangle();
                    Brush brush = new SolidBrush(e.ForeColor);
                    SizeF size = e.Graphics.MeasureString(item.ToString(), e.Font);
                    e.Graphics.DrawString(item.ToString(), e.Font, brush, e.Bounds.Left + (e.Bounds.Width / 2 - size.Width / 2), e.Bounds.Top + (e.Bounds.Height / 2 - size.Height / 2));
                }
            };

            listBox1.Hide();
        }
        private void button1_Click(object sender, EventArgs e) //結帳
        {
            if (rdBtn1.Checked || rdBtn2.Checked )
            {
                if (options.Where(x => x.checkBox.Checked && x.checkBox.Name != "checkBox7").Count() < 1)
                {
                    label8.Text = "請選擇餐點！";
                    label8.ForeColor = Color.Red;
                    return;
                }

                //label8 計價
                int sum = 0;
                options.ForEach(item =>
                {
                    if (item.checkBox.Checked)
                    {
                        sum += item.price * int.Parse(item.textBox.Text);
                    }
                });
                label8.Text = "計$ " + sum.ToString("#,0") + " 元";
                label8.ForeColor = Color.Black;


                //listBox清單
                if (sum > 0)
                {
                    listBox1.Items.Clear();
                    listBox1.Items.Add(string.Format(""));
                    listBox1.Items.Add(string.Format("餐飲清單"));
                    listBox1.Items.Add(string.Format(""));

                    int count = 0;
                    foreach (var item in options.Where(x => x.checkBox.Checked))
                    {
                        count++;
                        listBox1.Items.Add(string.Format($"{count,-1}.{item.checkBox.Text.Split(' ')[0],6}{item.price,4} × {item.textBox.Text,4}  =  {item.price*int.Parse(item.textBox.Text),7:#,0}"));
                    }
                    listBox1.Items.Add("".PadLeft(35,'-'));
                    listBox1.Items.Add(string.Format($"{"總計:",-18}{sum,15:#,0}"));
                    listBox1.Items.Add(string.Format(""));
                    listBox1.Items.Add(string.Format("謝謝惠顧！"));
                    listBox1.EndUpdate();
                    listBox1.Show();
                }
            }
            else
            {
                label8.Text = "請選擇內用或外帶！";
                label8.ForeColor = Color.Red;
            }
        }

        
        private void button2_Click(object sender, EventArgs e) //取消
        {
            options.ForEach(item =>
            {
                item.checkBox.Checked = false;
                item.textBox.Text = "";
            });
            rdBtn1.Checked = false;
            rdBtn2.Checked = false;
            label8.Text = "歡迎光臨！";
            label8.ForeColor = Color.Black;
            ChangeOption7(false);
            listBox1.Hide();
        }

        private void rdBtn1_CheckedChanged(object sender, EventArgs e)
        {
            ChangeOption7(false);
        }

        private void rdBtn2_CheckedChanged(object sender, EventArgs e)
        {
            ChangeOption7(true);
        }
        private void ChangeOption7(bool flag)
        {
            checkBox7.Visible = flag;
            checkBox7.Checked = flag;
            textBox7.Visible = flag;
            label7.Visible = flag;
            textBox7.Text = flag ? "1" : "0";
        }
    }
}
