using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class ViewForm : Form
    {
        public ViewForm(Form main)
        {
            InitializeComponent();

            var list = ((ListView)main.Controls["listView1"]).SelectedItems[0];

            pubLabel.Text += $" {list.SubItems[0].Text} {list.SubItems[1].Text}";
            priceLabel.Text += " " + list.SubItems[2].Text;
            cont1Label.Text += " " + list.SubItems[3].Text;
            cont2Label.Text += " " + list.SubItems[4].Text;
            cont3Label.Text += " " + list.SubItems[5].Text;
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }
    }
}