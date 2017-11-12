namespace MEMS_analyser_gui
{
    partial class parentForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(parentForm));
            this.topPanel = new System.Windows.Forms.Panel();
            this.vectorLabel = new System.Windows.Forms.Label();
            this.conderLabel = new System.Windows.Forms.Label();
            this.amountLabel = new System.Windows.Forms.Label();
            this.vectorAmount = new System.Windows.Forms.TextBox();
            this.conderAmount = new System.Windows.Forms.TextBox();
            this.leftPanel = new System.Windows.Forms.Panel();
            this.conderTypeLabel = new System.Windows.Forms.Label();
            this.inflatConder = new System.Windows.Forms.RadioButton();
            this.flatConder = new System.Windows.Forms.RadioButton();
            this.rightPanel = new System.Windows.Forms.Panel();
            this.infoLabel = new System.Windows.Forms.Label();
            this.gitLabel = new System.Windows.Forms.Label();
            this.gitLink = new System.Windows.Forms.LinkLabel();
            this.startButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.topPanel.SuspendLayout();
            this.leftPanel.SuspendLayout();
            this.rightPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // topPanel
            // 
            this.topPanel.BackColor = System.Drawing.Color.WhiteSmoke;
            this.topPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.topPanel.Controls.Add(this.vectorLabel);
            this.topPanel.Controls.Add(this.conderLabel);
            this.topPanel.Controls.Add(this.amountLabel);
            this.topPanel.Controls.Add(this.vectorAmount);
            this.topPanel.Controls.Add(this.conderAmount);
            this.topPanel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.topPanel.Location = new System.Drawing.Point(14, 13);
            this.topPanel.Name = "topPanel";
            this.topPanel.Size = new System.Drawing.Size(469, 175);
            this.topPanel.TabIndex = 0;
            // 
            // vectorLabel
            // 
            this.vectorLabel.AutoSize = true;
            this.vectorLabel.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.vectorLabel.Location = new System.Drawing.Point(10, 102);
            this.vectorLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.vectorLabel.Name = "vectorLabel";
            this.vectorLabel.Size = new System.Drawing.Size(86, 28);
            this.vectorLabel.TabIndex = 4;
            this.vectorLabel.Text = "Векторы";
            // 
            // conderLabel
            // 
            this.conderLabel.AutoSize = true;
            this.conderLabel.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.conderLabel.Location = new System.Drawing.Point(10, 58);
            this.conderLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.conderLabel.Name = "conderLabel";
            this.conderLabel.Size = new System.Drawing.Size(140, 28);
            this.conderLabel.TabIndex = 3;
            this.conderLabel.Text = "Конденсаторы";
            // 
            // amountLabel
            // 
            this.amountLabel.AutoSize = true;
            this.amountLabel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.amountLabel.Location = new System.Drawing.Point(10, 20);
            this.amountLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.amountLabel.Name = "amountLabel";
            this.amountLabel.Size = new System.Drawing.Size(226, 28);
            this.amountLabel.TabIndex = 2;
            this.amountLabel.Text = "Количество элементов:";
            this.amountLabel.Click += new System.EventHandler(this.amountLabel_Click);
            // 
            // vectorAmount
            // 
            this.vectorAmount.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vectorAmount.Location = new System.Drawing.Point(282, 102);
            this.vectorAmount.Margin = new System.Windows.Forms.Padding(3, 3, 30, 3);
            this.vectorAmount.Name = "vectorAmount";
            this.vectorAmount.Size = new System.Drawing.Size(154, 34);
            this.vectorAmount.TabIndex = 1;
            this.vectorAmount.Tag = "10";
            this.vectorAmount.Text = "10";
            this.vectorAmount.Click += new System.EventHandler(this.vectorAmount_Click);
            this.vectorAmount.TextChanged += new System.EventHandler(this.vectorAmount_TextChanged);
            // 
            // conderAmount
            // 
            this.conderAmount.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.conderAmount.Location = new System.Drawing.Point(282, 53);
            this.conderAmount.Margin = new System.Windows.Forms.Padding(30, 3, 3, 3);
            this.conderAmount.Name = "conderAmount";
            this.conderAmount.Size = new System.Drawing.Size(154, 34);
            this.conderAmount.TabIndex = 0;
            this.conderAmount.Tag = "10";
            this.conderAmount.Text = "10";
            this.conderAmount.Click += new System.EventHandler(this.conderAmount_Click);
            // 
            // leftPanel
            // 
            this.leftPanel.BackColor = System.Drawing.Color.WhiteSmoke;
            this.leftPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.leftPanel.Controls.Add(this.conderTypeLabel);
            this.leftPanel.Controls.Add(this.inflatConder);
            this.leftPanel.Controls.Add(this.flatConder);
            this.leftPanel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.leftPanel.Location = new System.Drawing.Point(14, 209);
            this.leftPanel.Name = "leftPanel";
            this.leftPanel.Size = new System.Drawing.Size(225, 119);
            this.leftPanel.TabIndex = 1;
            // 
            // conderTypeLabel
            // 
            this.conderTypeLabel.AutoSize = true;
            this.conderTypeLabel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.conderTypeLabel.Location = new System.Drawing.Point(6, 15);
            this.conderTypeLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.conderTypeLabel.Name = "conderTypeLabel";
            this.conderTypeLabel.Size = new System.Drawing.Size(150, 28);
            this.conderTypeLabel.TabIndex = 2;
            this.conderTypeLabel.Text = "Конденсаторы:";
            this.conderTypeLabel.Click += new System.EventHandler(this.conderTypeLabel_Click);
            // 
            // inflatConder
            // 
            this.inflatConder.AutoSize = true;
            this.inflatConder.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.inflatConder.Location = new System.Drawing.Point(10, 80);
            this.inflatConder.Margin = new System.Windows.Forms.Padding(10, 3, 3, 3);
            this.inflatConder.Name = "inflatConder";
            this.inflatConder.Size = new System.Drawing.Size(132, 32);
            this.inflatConder.TabIndex = 1;
            this.inflatConder.Text = "Неплоские";
            this.inflatConder.UseVisualStyleBackColor = true;
            this.inflatConder.CheckedChanged += new System.EventHandler(this.inflatConder_CheckedChanged);
            // 
            // flatConder
            // 
            this.flatConder.AutoSize = true;
            this.flatConder.Checked = true;
            this.flatConder.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.flatConder.Location = new System.Drawing.Point(10, 48);
            this.flatConder.Margin = new System.Windows.Forms.Padding(10, 3, 3, 3);
            this.flatConder.Name = "flatConder";
            this.flatConder.Size = new System.Drawing.Size(111, 32);
            this.flatConder.TabIndex = 0;
            this.flatConder.TabStop = true;
            this.flatConder.Text = "Плоские";
            this.flatConder.UseVisualStyleBackColor = true;
            this.flatConder.CheckedChanged += new System.EventHandler(this.flatConder_CheckedChanged);
            // 
            // rightPanel
            // 
            this.rightPanel.BackColor = System.Drawing.Color.WhiteSmoke;
            this.rightPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.rightPanel.Controls.Add(this.infoLabel);
            this.rightPanel.Controls.Add(this.gitLabel);
            this.rightPanel.Controls.Add(this.gitLink);
            this.rightPanel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rightPanel.Location = new System.Drawing.Point(260, 209);
            this.rightPanel.Name = "rightPanel";
            this.rightPanel.Size = new System.Drawing.Size(222, 119);
            this.rightPanel.TabIndex = 2;
            // 
            // infoLabel
            // 
            this.infoLabel.AutoSize = true;
            this.infoLabel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.infoLabel.Location = new System.Drawing.Point(10, 15);
            this.infoLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.infoLabel.Name = "infoLabel";
            this.infoLabel.Size = new System.Drawing.Size(140, 28);
            this.infoLabel.TabIndex = 2;
            this.infoLabel.Text = "О программе:";
            this.infoLabel.Click += new System.EventHandler(this.infoLabel_Click);
            // 
            // gitLabel
            // 
            this.gitLabel.AutoSize = true;
            this.gitLabel.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.gitLabel.Location = new System.Drawing.Point(10, 50);
            this.gitLabel.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.gitLabel.Name = "gitLabel";
            this.gitLabel.Size = new System.Drawing.Size(180, 28);
            this.gitLabel.TabIndex = 1;
            this.gitLabel.Text = "MEMS Analyser v1.0";
            // 
            // gitLink
            // 
            this.gitLink.ActiveLinkColor = System.Drawing.Color.DimGray;
            this.gitLink.AutoSize = true;
            this.gitLink.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.gitLink.Location = new System.Drawing.Point(10, 82);
            this.gitLink.Margin = new System.Windows.Forms.Padding(10, 0, 3, 0);
            this.gitLink.Name = "gitLink";
            this.gitLink.Size = new System.Drawing.Size(72, 28);
            this.gitLink.TabIndex = 0;
            this.gitLink.TabStop = true;
            this.gitLink.Text = "GitHub";
            this.gitLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.gitLink_LinkClicked);
            // 
            // startButton
            // 
            this.startButton.BackColor = System.Drawing.Color.WhiteSmoke;
            this.startButton.FlatAppearance.BorderSize = 2;
            this.startButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gainsboro;
            this.startButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            this.startButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.startButton.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.startButton.Location = new System.Drawing.Point(82, 348);
            this.startButton.Margin = new System.Windows.Forms.Padding(73, 3, 3, 3);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(135, 44);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "Построить";
            this.startButton.UseVisualStyleBackColor = false;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.Color.WhiteSmoke;
            this.exitButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.exitButton.FlatAppearance.BorderSize = 2;
            this.exitButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gainsboro;
            this.exitButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.exitButton.Font = new System.Drawing.Font("Segoe UI Semilight", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.exitButton.Location = new System.Drawing.Point(281, 348);
            this.exitButton.Margin = new System.Windows.Forms.Padding(3, 3, 73, 3);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(135, 44);
            this.exitButton.TabIndex = 4;
            this.exitButton.Text = "Выход";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // parentForm
            // 
            this.AcceptButton = this.startButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 23F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.CancelButton = this.exitButton;
            this.ClientSize = new System.Drawing.Size(497, 403);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.rightPanel);
            this.Controls.Add(this.leftPanel);
            this.Controls.Add(this.topPanel);
            this.Font = new System.Drawing.Font("Consolas", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.Name = "parentForm";
            this.Text = "MEMS Analyser";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.topPanel.ResumeLayout(false);
            this.topPanel.PerformLayout();
            this.leftPanel.ResumeLayout(false);
            this.leftPanel.PerformLayout();
            this.rightPanel.ResumeLayout(false);
            this.rightPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel topPanel;
        private System.Windows.Forms.TextBox vectorAmount;
        private System.Windows.Forms.TextBox conderAmount;
        private System.Windows.Forms.Panel leftPanel;
        private System.Windows.Forms.RadioButton inflatConder;
        private System.Windows.Forms.RadioButton flatConder;
        private System.Windows.Forms.Panel rightPanel;
        private System.Windows.Forms.Label conderTypeLabel;
        private System.Windows.Forms.Label amountLabel;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Label conderLabel;
        private System.Windows.Forms.Label vectorLabel;
        private System.Windows.Forms.Label gitLabel;
        private System.Windows.Forms.LinkLabel gitLink;
        private System.Windows.Forms.Label infoLabel;
    }
}

