using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class AddForm : Form
    {
        public Publisher Result;
        public string imageName;

        public AddForm()
        {
            InitializeComponent();
        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                imageName = dialog.FileName;
                try
                {
                    pictureBox.Image = Image.FromFile(imageName);
                }
                catch (OutOfMemoryException) { return; }
            }
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if (authorTextBox.Text == "" ||
                nameTextBox.Text == "" ||
                priceTextBox.Text == "" ||
                contTextBox.Text == "")
            {
                MessageBox.Show("Необходимо заполнить все поля!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (pictureBox.Image == null)
            {
                MessageBox.Show("Вставьте картинку!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (MainForm.IsInt(authorTextBox.Text) ||
                MainForm.IsInt(nameTextBox.Text))
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
                MessageBox.Show("Поле 'Стоимость' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Result = new Publisher(
                nameTextBox.Text,
                authorTextBox.Text,
                Convert.ToInt32(priceTextBox.Text),
                contTextBox.Text,
                DateTime.Now,
                imageName
            );

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}