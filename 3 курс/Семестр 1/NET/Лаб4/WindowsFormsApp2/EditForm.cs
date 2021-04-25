using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class EditForm : Form
    {
        public Publisher Result;
        public string imageName;

        public EditForm(Publisher main)
        {
            InitializeComponent();

            nameTextBox.Text = main.name;
            authorTextBox.Text = main.author;
            priceTextBox.Text = main.price.ToString();
            contTextBox.Text = main.contents;
            pictureBox.Image = Image.FromFile(main.photo);
            pictureBox.ImageLocation = main.photo;
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
                    pictureBox.ImageLocation = imageName;
                }
                catch (OutOfMemoryException) { return; }
            }
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            if (nameTextBox.Text == "" ||
               authorTextBox.Text == "" ||
               priceTextBox.Text == "" ||
               contTextBox.Text == "")
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
                MessageBox.Show("Поле 'Стоимость' введено не верно!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Result = new Publisher(
                nameTextBox.Text,
                authorTextBox.Text,
                Convert.ToInt32(priceTextBox.Text),
                contTextBox.Text,
                DateTime.Now,
                pictureBox.ImageLocation
            );

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}