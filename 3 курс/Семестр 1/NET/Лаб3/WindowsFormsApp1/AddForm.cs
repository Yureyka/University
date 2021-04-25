using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class AddForm : Form
    {
        public AddForm()
        {
            InitializeComponent();
        }

        private void addButton_Click(object sender, EventArgs e)
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
                MessageBox.Show("В поле 'Название' или 'Автор' содержатся цифры!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            try
            {
                Convert.ToInt32(priceTextBox.Text);
            }
            catch
            {
                MessageBox.Show("Поле 'Оценка' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            DialogResult = DialogResult.OK;
        }
    }
}