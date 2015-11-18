#pragma once

namespace KamiPls {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lUserPosText;
	private: System::Windows::Forms::Label^ lMobPosText;
	private: System::Windows::Forms::Label^ lMobPos;
	private: System::Windows::Forms::Label^ lUserPos;
	private: System::Windows::Forms::Timer^ tUpdateUI;
	private: System::Windows::Forms::CheckBox^ cbTimer;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lUserPosText = (gcnew System::Windows::Forms::Label());
			this->lMobPosText = (gcnew System::Windows::Forms::Label());
			this->lMobPos = (gcnew System::Windows::Forms::Label());
			this->lUserPos = (gcnew System::Windows::Forms::Label());
			this->tUpdateUI = (gcnew System::Windows::Forms::Timer(this->components));
			this->cbTimer = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// lUserPosText
			// 
			this->lUserPosText->AutoSize = true;
			this->lUserPosText->Location = System::Drawing::Point(12, 9);
			this->lUserPosText->Name = L"lUserPosText";
			this->lUserPosText->Size = System::Drawing::Size(60, 13);
			this->lUserPosText->TabIndex = 0;
			this->lUserPosText->Text = L"current pos";
			// 
			// lMobPosText
			// 
			this->lMobPosText->AutoSize = true;
			this->lMobPosText->Location = System::Drawing::Point(12, 22);
			this->lMobPosText->Name = L"lMobPosText";
			this->lMobPosText->Size = System::Drawing::Size(63, 13);
			this->lMobPosText->TabIndex = 1;
			this->lMobPosText->Text = L"closest mob";
			// 
			// lMobPos
			// 
			this->lMobPos->AutoSize = true;
			this->lMobPos->Location = System::Drawing::Point(81, 22);
			this->lMobPos->Name = L"lMobPos";
			this->lMobPos->Size = System::Drawing::Size(30, 13);
			this->lMobPos->TabIndex = 3;
			this->lMobPos->Text = L"{0;0}";
			// 
			// lUserPos
			// 
			this->lUserPos->AutoSize = true;
			this->lUserPos->Location = System::Drawing::Point(81, 9);
			this->lUserPos->Name = L"lUserPos";
			this->lUserPos->Size = System::Drawing::Size(30, 13);
			this->lUserPos->TabIndex = 2;
			this->lUserPos->Text = L"{0;0}";
			// 
			// tUpdateUI
			// 
			this->tUpdateUI->Interval = 1000;
			this->tUpdateUI->Tick += gcnew System::EventHandler(this, &MainForm::tUpdateUI_Tick);
			// 
			// cbTimer
			// 
			this->cbTimer->AutoSize = true;
			this->cbTimer->Location = System::Drawing::Point(12, 38);
			this->cbTimer->Name = L"cbTimer";
			this->cbTimer->Size = System::Drawing::Size(84, 17);
			this->cbTimer->TabIndex = 4;
			this->cbTimer->Text = L"Enable timer";
			this->cbTimer->UseVisualStyleBackColor = true;
			this->cbTimer->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbTimer_CheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->cbTimer);
			this->Controls->Add(this->lMobPos);
			this->Controls->Add(this->lUserPos);
			this->Controls->Add(this->lMobPosText);
			this->Controls->Add(this->lUserPosText);
			this->Name = L"MainForm";
			this->Text = L"KamiPls";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tUpdateUI_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cbTimer_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	};
}

