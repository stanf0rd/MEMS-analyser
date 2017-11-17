using System;
using System.IO;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System.Timers;
using System.Reflection;
using System.Runtime.InteropServices;

namespace MEMS_analyser_gui
{
    
    public partial class parentForm : Form
    {
        [DllImport("mems_dll.dll", CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int build(int a);
        public bool IsProcessOpen(string name)
        {
            foreach (Process clsProcess in Process.GetProcesses())
            {
                if (clsProcess.ProcessName.Contains(name))
                {
                    //if the process is found to be running then we
                    //return a true
                    return true;
                }
            }
            //otherwise we return a false
            return false;
        }

        //string conderType = ""; //to activate the feature add "flat" between ""
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
        void OnTimedEvent(object source, ElapsedEventArgs e)
        {
            startButton.BackColor = Color.Red;
        }

       unsafe private void startButton_Click(object sender, EventArgs e)
        {
            
            foreach (Process proc in Process.GetProcessesByName("MEMS-analyser")) proc.Kill();
            String appFile = "MEMS-analyser.exe";
            if (File.Exists(appFile))
            {
            String args = conderAmount.Text + " " + vectorAmount.Text;// + " " + conderType;
               Process.Start(appFile, args);
           }
           else
           {
               noAppFileError.SetError(startButton, "Не найден файл программы. Пожалуйста, разместите MEMS-analyser.exe в том же каталоге");

           }
           
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            foreach (Process proc in Process.GetProcessesByName("MEMS-analyser")) proc.Kill();
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
                //conderType = ""; //to activate the feature add "flat" between ""
            }
        }

        private void inflatConder_CheckedChanged(object sender, EventArgs e)
        {
            if (inflatConder.Checked == true)
            {
                //conderType = ""; //to activate the feature add "inflat" between ""
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
