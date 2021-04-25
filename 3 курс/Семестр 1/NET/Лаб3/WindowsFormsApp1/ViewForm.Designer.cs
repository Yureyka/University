namespace WindowsFormsApp1
{
    partial class ViewForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewForm));
            this.pubLabel = new System.Windows.Forms.Label();
            this.priceLabel = new System.Windows.Forms.Label();
            this.cont1Label = new System.Windows.Forms.Label();
            this.cont3Label = new System.Windows.Forms.Label();
            this.cont2Label = new System.Windows.Forms.Label();
            this.closeButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // pubLabel
            // 
            this.pubLabel.AutoSize = true;
            this.pubLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.pubLabel.Location = new System.Drawing.Point(12, 9);
            this.pubLabel.Name = "pubLabel";
            this.pubLabel.Size = new System.Drawing.Size(69, 18);
            this.pubLabel.TabIndex = 1;
            this.pubLabel.Text = "Книга:";
            // 
            // priceLabel
            // 
            this.priceLabel.AutoSize = true;
            this.priceLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.priceLabel.Location = new System.Drawing.Point(12, 40);
            this.priceLabel.Name = "priceLabel";
            this.priceLabel.Size = new System.Drawing.Size(64, 18);
            this.priceLabel.TabIndex = 2;
            this.priceLabel.Text = "Стоимость:";
            // 
            // cont1Label
            // 
            this.cont1Label.AutoSize = true;
            this.cont1Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cont1Label.Location = new System.Drawing.Point(12, 113);
            this.cont1Label.Name = "cont1Label";
            this.cont1Label.Size = new System.Drawing.Size(76, 18);
            this.cont1Label.TabIndex = 3;
            this.cont1Label.Text = "Глава 1:";
            // 
            // cont3Label
            // 
            this.cont3Label.AutoSize = true;
            this.cont3Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cont3Label.Location = new System.Drawing.Point(12, 175);
            this.cont3Label.Name = "cont3Label";
            this.cont3Label.Size = new System.Drawing.Size(76, 18);
            this.cont3Label.TabIndex = 4;
            this.cont3Label.Text = "Глава 3:";
            // 
            // cont2Label
            // 
            this.cont2Label.AutoSize = true;
            this.cont2Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cont2Label.Location = new System.Drawing.Point(12, 144);
            this.cont2Label.Name = "cont2Label";
            this.cont2Label.Size = new System.Drawing.Size(76, 18);
            this.cont2Label.TabIndex = 5;
            this.cont2Label.Text = "Глава 2:";
            // 
            // closeButton
            // 
            this.closeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closeButton.Location = new System.Drawing.Point(100, 231);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(109, 34);
            this.closeButton.TabIndex = 13;
            this.closeButton.Text = "Закрыть";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // ViewForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(308, 277);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.cont2Label);
            this.Controls.Add(this.cont3Label);
            this.Controls.Add(this.cont1Label);
            this.Controls.Add(this.priceLabel);
            this.Controls.Add(this.pubLabel);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "ViewForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Просмотр";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label pubLabel;
        private System.Windows.Forms.Label priceLabel;
        private System.Windows.Forms.Label cont1Label;
        private System.Windows.Forms.Label cont3Label;
        private System.Windows.Forms.Label cont2Label;
        private System.Windows.Forms.Button closeButton;
    }
}