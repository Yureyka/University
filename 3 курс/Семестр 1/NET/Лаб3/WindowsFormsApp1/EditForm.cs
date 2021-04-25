using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class EditForm : Form
    {
        public EditForm(Form main)
        {
            InitializeComponent();

            var list = ((ListView)main.Controls["listView1"]).SelectedItems[0];

            nameTextBox.Text += list.SubItems[1].Text;
            authorTextBox.Text += list.SubItems[0].Text;
            priceTextBox.Text += list.SubItems[2].Text;
            cont1TextBox.Text += list.SubItems[3].Text;
            cont2TextBox.Text += list.SubItems[4].Text;
            cont3TextBox.Text += list.SubItems[5].Text;
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            if (nameTextBox.Text == "" ||
               authorTextBox.Text == "" ||
               priceTextBox.Text == "" ||
               cont1TextBox.Text == "" ||
               cont2TextBox.Text == "" ||
               cont3TextBox.Text == "")
            {
                MessageBox.Show("Необходимо заполнить все поля!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (MainForm.IsInt(nameTextBox.Text) ||
                MainForm.IsInt(authorTextBox.Text))
            {
                MessageBox.Show("В поле 'Название' или 'Автор' не должны содержаться цифры!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            try
            {
                Convert.ToInt32(priceTextBox.Text);
            }
            catch
            {
                MessageBox.Show("Поле 'Стоимость' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            DialogResult = DialogResult.OK;
        }
    }
}