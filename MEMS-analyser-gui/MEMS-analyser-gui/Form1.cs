using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;


namespace MEMS_analyser_gui
{
    public partial class parentForm : Form
    {
        string conderType = ""; //to activate the feature add "flat" between ""
        public parentForm()
        {
            InitializeComponent();
        }

        private void conderAmount_Click(object sender, EventArgs e)
        {
            conderAmount.SelectAll();

        }

        private void vectorAmount_Click(object sender, EventArgs e)
        {
            vectorAmount.SelectAll();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            String appFile = "MEMS-analyser.exe";
            String args = conderAmount.Text + " " + vectorAmount.Text + " " + conderType;
            Process.Start(appFile, args);
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void gitLink_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Process.Start("https://github.com/stanf0rd/MEMS-analyser");

        }

        private void conderTypeLabel_Click(object sender, EventArgs e)
        {

        }

        private void flatConder_CheckedChanged(object sender, EventArgs e)
        {
            if (flatConder.Checked == true)
            {
                conderType = ""; //to activate the feature add "flat" between ""
            }
        }

        private void inflatConder_CheckedChanged(object sender, EventArgs e)
        {
            if (inflatConder.Checked == true)
            {
                conderType = ""; //to activate the feture add "inflat" between ""
            }
        }

        private void infoLabel_Click(object sender, EventArgs e)
        {

        }

        private void amountLabel_Click(object sender, EventArgs e)
        {

        }

        private void vectorAmount_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
