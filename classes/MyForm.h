#pragma once
#include "loads.h"
#include <msclr/marshal_cppstd.h>
#include"filehandling.h"
#include"calc.h"
#include"alarm.h"
namespace CS_team {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;









	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(73, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"alarm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 35);
			this->label1->TabIndex = 1;
			this->label1->Text = L"input file :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(464, 90);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"calculations";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(145, 447);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(104, 29);
			this->textBox1->TabIndex = 12;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(145, 386);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(104, 29);
			this->textBox8->TabIndex = 19;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(145, 510);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(104, 29);
			this->textBox9->TabIndex = 20;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 450);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"max current";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 389);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"max voltage";
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Andalus", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(13, 507);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 26);
			this->label7->TabIndex = 23;
			this->label7->Text = L"time limit";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(166, 92);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 30);
			this->textBox2->TabIndex = 25;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(758, 90);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 32);
			this->button3->TabIndex = 26;
			this->button3->Text = L"load details";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(166, 157);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(166, 30);
			this->textBox3->TabIndex = 27;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 35);
			this->label2->TabIndex = 28;
			this->label2->Text = L"output file :";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 559);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		msclr::interop::marshal_context context; 
		std::string file = context.marshal_as<std::string>(textBox2->Text);
	
	
		readfile(file, current, voltage, timevec);
		double maxcurrent, maxvolt, timelimit;
		
	
		maxcurrent = System::Convert::ToDouble(textBox1->Text);
		maxvolt = System::Convert::ToDouble(textBox8->Text);
		timelimit = System::Convert::ToDouble(textBox9->Text);
		string message = monitor_alarm(maxcurrent, maxvolt, timelimit, current, voltage, timevec);
		MessageBox::Show(gcnew String(message.c_str()), "message box", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	
	}
		   

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		msclr::interop::marshal_context context;
		std::string file = context.marshal_as<std::string>(textBox2->Text);
		msclr::interop::marshal_context context1;
		std::string ofile = context1.marshal_as<std::string>(textBox3->Text);

		readfile(file, current, voltage, timevec);
		
		Low_pass_filter(current, voltage, timevec);
	    double Cfreq = 1.0/(periodic_time_after_filter(current, timevec));
	    double Vfreq =1.0/(periodic_time_after_filter(voltage, timevec));
		double power = PowerCalc(current, voltage, timevec);
		double powerfactor = PowerFactorCalc(current, voltage, timevec);
		double Energy = energycalc(current, voltage, timevec);
		double Cost = calculateTariff(Energy, timevec);
		String^ Cfreqs = Cfreq.ToString();
		String^ Vfreqs = Vfreq.ToString();
		String^ powers = power.ToString();
		String^ powerfactors = powerfactor.ToString();
		String^ Energys = Energy.ToString();
	    String^ Costs = Cost.ToString();
		String^ calculations = "current frequency (hz): " + Cfreqs + "\n" + "voltage frequency (hz): " + Vfreqs + "\n" + "average power (W): " + powers + "\n" + "power factor:"
			+ powerfactors + "\n" + "Energy (KWh):" + Energys + "\n" + "Energy cost (EGP): " + Costs + "\n\n\n"+"do you want to save the output data in a file?"+"\n" ;
		if (MessageBox::Show(calculations, "Results", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
		{
			outputdata(ofile, power, powerfactor, Cfreq, Vfreq, Energy, Cost);
		}
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	loads myload;
	msclr::interop::marshal_context context;
	std::string file = context.marshal_as<std::string>(textBox2->Text);

	readfile(file, current, voltage, timevec);

	Low_pass_filter(current, voltage, timevec);

	double peakcurrent = myload.Peak(current, timevec);
		double peakvolt=myload.Peak(voltage, timevec);
		double rmscurrent = myload.RMS(current, timevec);
		double rmsvolt= myload.RMS(voltage, timevec);
		double power = PowerCalc(current, voltage, timevec);
		double Voltfreq = 1.0 / (periodic_time_after_filter(voltage, timevec));
		myload.setname(file);
		myload.setcurrent(peakcurrent);
		myload.setvoltage(peakvolt);
		myload.myloadproperties.current=rmscurrent;
		myload.myloadproperties.voltage = rmsvolt;
		myload.myloadproperties.power = power;
		myload.myloadproperties.frequancy = Voltfreq;
		String^ peakcurrents = peakcurrent.ToString();
		String^ peakvolts = peakvolt.ToString();
		String^ powers = power.ToString();
		String^ rmscurrents = rmscurrent.ToString();
		String^ rmsvolts = rmsvolt.ToString();
		String^ Voltfreqs = Voltfreq.ToString();
		String^ properties= "current (A) : " + rmscurrents + "\n" + "voltage (V): " + rmsvolts + "\n" + "power (W): " + powers + "\n" + "peak current (A):"
			+ peakcurrents + "\n" + "peak voltage (V): " + peakvolts + "\n" + "frequency (hz): " + Voltfreqs + "\n";
		
		MessageBox::Show(properties, "Results", MessageBoxButtons::OK, MessageBoxIcon::Information);





}
	  


};
}
