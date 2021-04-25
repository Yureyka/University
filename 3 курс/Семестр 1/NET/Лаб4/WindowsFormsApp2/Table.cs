using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Table : Form
    {
        public BindingList<Publisher> pubs = new BindingList<Publisher>();
        public DataGridView DataGridView { get { return dataGridView1; } }

        public Table()
        {
            InitializeComponent();

            dataGridView1.DataSource = pubs;

            Closing += (sender, e) =>
            {
                MainForm c = (MainForm) MdiParent;
                c.windowNumber--;
            };
        }

        public Table(IEnumerable<Publisher> pubsCollection) : this()
        {
            foreach (Publisher field in pubsCollection)
            {
                pubs.Add(field);
            }
        }

        private void dataGridView1_Sorted(object sender, System.EventArgs e)
        {

        }
    }
}