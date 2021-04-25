using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class MainForm : Form
    {
        private List<Publisher> pubs = new List<Publisher>();

        public MainForm()
        {
            InitializeComponent();
        }

        private void UpdateList()
        {
            listView1.Items.Clear();

            foreach (Publisher pub in pubs)
            {
                listView1.Items.Add(new ListViewItem(new string[] {
                    pub.name,
                    pub.author,
                    pub.price.ToString(),
                    pub.contents[0],
                    pub.contents[1],
                    pub.contents[2]
                }));
            }
        }

        public static bool IsInt(string str)
        {
            foreach (char c in str)
            {
                if (c < '0' || c > '9')
                    return false;
            }

            return true;
        }

        private void посмотретьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Вы должны выбрать книгу!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            ViewForm viewForm = new ViewForm(this);

            viewForm.ShowDialog();
        }

        private void добавитьToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            AddForm addForm = new AddForm();

            if (addForm.ShowDialog() == DialogResult.OK)
            {
                pubs.Add(new Publisher(
                    ((TextBox)addForm.Controls["nameTextBox"]).Text,
                    ((TextBox)addForm.Controls["authorTextBox"]).Text,
                    Convert.ToDouble(((TextBox)addForm.Controls["priceTextBox"]).Text),
                    new string[] {
                        ((TextBox)addForm.Controls["cont1TextBox"]).Text,
                        ((TextBox)addForm.Controls["cont2TextBox"]).Text,
                        ((TextBox)addForm.Controls["cont3TextBox"]).Text
                    }
                ));
            }

            UpdateList();
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Выберите книгу для удаления!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            pubs.RemoveAt(listView1.SelectedIndices[0]);

            UpdateList();
        }

        private void редактироватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
            {
                MessageBox.Show("Выберите книгу для редактирования!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            EditForm editForm = new EditForm(this);

            if (editForm.ShowDialog() == DialogResult.OK)
            {
                pubs.RemoveAt(listView1.SelectedIndices[0]);
                pubs.Insert(listView1.SelectedIndices[0], new Publisher(
                    ((TextBox)editForm.Controls["authorTextBox"]).Text,
                    ((TextBox)editForm.Controls["nameTextBox"]).Text,
                    Convert.ToInt32(((TextBox)editForm.Controls["priceTextBox"]).Text),
                    new string[] {
                        ((TextBox)editForm.Controls["cont1TextBox"]).Text,
                        ((TextBox)editForm.Controls["cont2TextBox"]).Text,
                        ((TextBox)editForm.Controls["cont3TextBox"]).Text
                    }
                ));
            }

            UpdateList();
        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Лабораторная работа №3", "О программе", MessageBoxButtons.OK, MessageBoxIcon.Asterisk, MessageBoxDefaultButton.Button1);
        }
    }
}