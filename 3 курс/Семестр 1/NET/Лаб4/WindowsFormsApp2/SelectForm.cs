using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class SelectForm : Form
    {
        public List<Publisher> results = new List<Publisher>();
        private readonly Table _active;

        public SelectForm(Table active)
        {
            InitializeComponent();

            _active = active;
        }

        private void selectButton_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < _active.DataGridView.RowCount; i++)
            {
                if (_active.DataGridView.Rows[i].Cells[0].Value.ToString().Contains(nameTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[1].Value.ToString().Contains(authorTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[3].Value.ToString().Contains(priceTextBox.Text) &&
                    _active.DataGridView.Rows[i].Cells[4].Value.ToString().Contains(contTextBox.Text))
                {
                    Publisher Result = new Publisher(
                       _active.DataGridView.Rows[i].Cells[0].Value.ToString(),
                       _active.DataGridView.Rows[i].Cells[1].Value.ToString(),
                       Convert.ToInt32(_active.DataGridView.Rows[i].Cells[2].Value),
                       _active.DataGridView.Rows[i].Cells[3].Value.ToString(),
                       Convert.ToDateTime(_active.DataGridView.Rows[i].Cells[4].Value),
                       _active.DataGridView.Rows[i].Cells[5].Value.ToString()
                    );
                    results.Add(Result);
                }
            }

            DialogResult = DialogResult.OK;
            Close();
        }
    }
}