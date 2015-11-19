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
	private: System::Windows::Forms::NumericUpDown^  nudXOffset;
	private: System::Windows::Forms::NumericUpDown^  nudYOffset;
	private: System::Windows::Forms::CheckBox^  cbKami;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::Windows::Forms::GroupBox^  gbKami;
				 System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
				 System::Windows::Forms::Label^  label1;
				 System::Windows::Forms::Label^  label2;
				 this->nudXOffset = (gcnew System::Windows::Forms::NumericUpDown());
				 this->nudYOffset = (gcnew System::Windows::Forms::NumericUpDown());
				 this->cbKami = (gcnew System::Windows::Forms::CheckBox());
				 gbKami = (gcnew System::Windows::Forms::GroupBox());
				 tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 label1 = (gcnew System::Windows::Forms::Label());
				 label2 = (gcnew System::Windows::Forms::Label());
				 gbKami->SuspendLayout();
				 tableLayoutPanel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudXOffset))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudYOffset))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // gbKami
				 // 
				 gbKami->AutoSize = true;
				 gbKami->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 gbKami->Controls->Add(tableLayoutPanel1);
				 gbKami->Dock = System::Windows::Forms::DockStyle::Fill;
				 gbKami->Location = System::Drawing::Point(0, 0);
				 gbKami->Name = L"gbKami";
				 gbKami->Size = System::Drawing::Size(172, 98);
				 gbKami->TabIndex = 0;
				 gbKami->TabStop = false;
				 gbKami->Text = L"KamiPls";
				 // 
				 // tableLayoutPanel1
				 // 
				 tableLayoutPanel1->AutoSize = true;
				 tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 tableLayoutPanel1->ColumnCount = 2;
				 tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
				 tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
				 tableLayoutPanel1->Controls->Add(label1, 0, 0);
				 tableLayoutPanel1->Controls->Add(label2, 0, 1);
				 tableLayoutPanel1->Controls->Add(this->nudXOffset, 1, 0);
				 tableLayoutPanel1->Controls->Add(this->nudYOffset, 1, 1);
				 tableLayoutPanel1->Controls->Add(this->cbKami, 0, 2);
				 tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 tableLayoutPanel1->Location = System::Drawing::Point(3, 16);
				 tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 tableLayoutPanel1->RowCount = 3;
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel1->Size = System::Drawing::Size(166, 79);
				 tableLayoutPanel1->TabIndex = 0;
				 // 
				 // label1
				 // 
				 label1->AutoSize = true;
				 label1->Dock = System::Windows::Forms::DockStyle::Fill;
				 label1->Location = System::Drawing::Point(3, 0);
				 label1->Name = L"label1";
				 label1->Size = System::Drawing::Size(40, 26);
				 label1->TabIndex = 0;
				 label1->Text = L"xOffset";
				 label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // label2
				 // 
				 label2->AutoSize = true;
				 label2->Dock = System::Windows::Forms::DockStyle::Fill;
				 label2->Location = System::Drawing::Point(3, 26);
				 label2->Name = L"label2";
				 label2->Size = System::Drawing::Size(40, 26);
				 label2->TabIndex = 1;
				 label2->Text = L"yOffset";
				 label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // nudXOffset
				 // 
				 this->nudXOffset->AutoSize = true;
				 this->nudXOffset->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->nudXOffset->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
				 this->nudXOffset->Location = System::Drawing::Point(49, 3);
				 this->nudXOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
				 this->nudXOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
				 this->nudXOffset->Name = L"nudXOffset";
				 this->nudXOffset->Size = System::Drawing::Size(114, 20);
				 this->nudXOffset->TabIndex = 2;
				 this->nudXOffset->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudXOffset_ValueChanged);
				 // 
				 // nudYOffset
				 // 
				 this->nudYOffset->AutoSize = true;
				 this->nudYOffset->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->nudYOffset->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
				 this->nudYOffset->Location = System::Drawing::Point(49, 29);
				 this->nudYOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
				 this->nudYOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
				 this->nudYOffset->Name = L"nudYOffset";
				 this->nudYOffset->Size = System::Drawing::Size(114, 20);
				 this->nudYOffset->TabIndex = 3;
				 this->nudYOffset->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudYOffset_ValueChanged);
				 // 
				 // cbKami
				 // 
				 this->cbKami->AutoCheck = false;
				 this->cbKami->AutoSize = true;
				 tableLayoutPanel1->SetColumnSpan(this->cbKami, 2);
				 this->cbKami->Location = System::Drawing::Point(3, 55);
				 this->cbKami->Name = L"cbKami";
				 this->cbKami->Size = System::Drawing::Size(65, 17);
				 this->cbKami->TabIndex = 4;
				 this->cbKami->Text = L"Enabled";
				 this->cbKami->UseVisualStyleBackColor = true;
				 this->cbKami->Click += gcnew System::EventHandler(this, &MainForm::cbKami_Click);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->ClientSize = System::Drawing::Size(172, 98);
				 this->Controls->Add(gbKami);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				 this->Name = L"MainForm";
				 this->Text = L"KamiPls";
				 gbKami->ResumeLayout(false);
				 gbKami->PerformLayout();
				 tableLayoutPanel1->ResumeLayout(false);
				 tableLayoutPanel1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudXOffset))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudYOffset))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private:
		void cbKami_Click(System::Object^ sender, System::EventArgs^ e);
		void nudXOffset_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		void nudYOffset_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	};
}

