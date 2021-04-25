using System;
using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class ViewForm : Form
    {
        public Publisher Result;
        public ViewForm(Publisher main)
        {
            InitializeComponent();

            pubLabel.Text += $" {main.name} {main.author}";
            priceLabel.Text += " " + main.price;
            contLabel.Text += " " + main.contents;
            dateLabel.Text += " " + main.date;
            pictureBox.Image = Image.FromFile(main.photo);
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }
    }
}