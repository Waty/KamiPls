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
			ddbMode->SelectedIndex = 0;
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
	private: System::Windows::Forms::NumericUpDown^  nudLootX;
	private: System::Windows::Forms::NumericUpDown^  nudLootY;
	private: System::Windows::Forms::ComboBox^  ddbMode;
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
				 System::Windows::Forms::GroupBox^  groupBox1;
				 System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
				 System::Windows::Forms::Label^  label3;
				 System::Windows::Forms::Label^  label4;
				 this->nudXOffset = (gcnew System::Windows::Forms::NumericUpDown());
				 this->nudYOffset = (gcnew System::Windows::Forms::NumericUpDown());
				 this->nudLootX = (gcnew System::Windows::Forms::NumericUpDown());
				 this->nudLootY = (gcnew System::Windows::Forms::NumericUpDown());
				 this->cbKami = (gcnew System::Windows::Forms::CheckBox());
				 this->ddbMode = (gcnew System::Windows::Forms::ComboBox());
				 gbKami = (gcnew System::Windows::Forms::GroupBox());
				 tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 label1 = (gcnew System::Windows::Forms::Label());
				 label2 = (gcnew System::Windows::Forms::Label());
				 groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 label3 = (gcnew System::Windows::Forms::Label());
				 label4 = (gcnew System::Windows::Forms::Label());
				 gbKami->SuspendLayout();
				 tableLayoutPanel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudXOffset))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudYOffset))->BeginInit();
				 groupBox1->SuspendLayout();
				 tableLayoutPanel2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLootX))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLootY))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // gbKami
				 // 
				 gbKami->AutoSize = true;
				 gbKami->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 gbKami->Controls->Add(tableLayoutPanel1);
				 gbKami->Location = System::Drawing::Point(12, 12);
				 gbKami->Name = L"gbKami";
				 gbKami->Size = System::Drawing::Size(111, 71);
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
				 tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 tableLayoutPanel1->Location = System::Drawing::Point(3, 16);
				 tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 tableLayoutPanel1->RowCount = 2;
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				 tableLayoutPanel1->Size = System::Drawing::Size(105, 52);
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
				 this->nudXOffset->Size = System::Drawing::Size(53, 20);
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
				 this->nudYOffset->Size = System::Drawing::Size(53, 20);
				 this->nudYOffset->TabIndex = 3;
				 this->nudYOffset->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudYOffset_ValueChanged);
				 // 
				 // groupBox1
				 // 
				 groupBox1->AutoSize = true;
				 groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 groupBox1->Controls->Add(tableLayoutPanel2);
				 groupBox1->Location = System::Drawing::Point(129, 12);
				 groupBox1->Name = L"groupBox1";
				 groupBox1->Size = System::Drawing::Size(111, 71);
				 groupBox1->TabIndex = 1;
				 groupBox1->TabStop = false;
				 groupBox1->Text = L"LootPls";
				 // 
				 // tableLayoutPanel2
				 // 
				 tableLayoutPanel2->AutoSize = true;
				 tableLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 tableLayoutPanel2->ColumnCount = 2;
				 tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
				 tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
				 tableLayoutPanel2->Controls->Add(label3, 0, 0);
				 tableLayoutPanel2->Controls->Add(label4, 0, 1);
				 tableLayoutPanel2->Controls->Add(this->nudLootX, 1, 0);
				 tableLayoutPanel2->Controls->Add(this->nudLootY, 1, 1);
				 tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
				 tableLayoutPanel2->Location = System::Drawing::Point(3, 16);
				 tableLayoutPanel2->Name = L"tableLayoutPanel2";
				 tableLayoutPanel2->RowCount = 2;
				 tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
				 tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				 tableLayoutPanel2->Size = System::Drawing::Size(105, 52);
				 tableLayoutPanel2->TabIndex = 0;
				 // 
				 // label3
				 // 
				 label3->AutoSize = true;
				 label3->Dock = System::Windows::Forms::DockStyle::Fill;
				 label3->Location = System::Drawing::Point(3, 0);
				 label3->Name = L"label3";
				 label3->Size = System::Drawing::Size(40, 26);
				 label3->TabIndex = 0;
				 label3->Text = L"xOffset";
				 label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // label4
				 // 
				 label4->AutoSize = true;
				 label4->Dock = System::Windows::Forms::DockStyle::Fill;
				 label4->Location = System::Drawing::Point(3, 26);
				 label4->Name = L"label4";
				 label4->Size = System::Drawing::Size(40, 26);
				 label4->TabIndex = 1;
				 label4->Text = L"yOffset";
				 label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // nudLootX
				 // 
				 this->nudLootX->AutoSize = true;
				 this->nudLootX->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->nudLootX->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
				 this->nudLootX->Location = System::Drawing::Point(49, 3);
				 this->nudLootX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
				 this->nudLootX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
				 this->nudLootX->Name = L"nudLootX";
				 this->nudLootX->Size = System::Drawing::Size(53, 20);
				 this->nudLootX->TabIndex = 2;
				 this->nudLootX->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudLootX_ValueChanged);
				 // 
				 // nudLootY
				 // 
				 this->nudLootY->AutoSize = true;
				 this->nudLootY->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->nudLootY->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
				 this->nudLootY->Location = System::Drawing::Point(49, 29);
				 this->nudLootY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
				 this->nudLootY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
				 this->nudLootY->Name = L"nudLootY";
				 this->nudLootY->Size = System::Drawing::Size(53, 20);
				 this->nudLootY->TabIndex = 3;
				 this->nudLootY->ValueChanged += gcnew System::EventHandler(this, &MainForm::nudLootY_ValueChanged);
				 // 
				 // cbKami
				 // 
				 this->cbKami->AutoCheck = false;
				 this->cbKami->AutoSize = true;
				 this->cbKami->Location = System::Drawing::Point(15, 91);
				 this->cbKami->Name = L"cbKami";
				 this->cbKami->Size = System::Drawing::Size(65, 17);
				 this->cbKami->TabIndex = 4;
				 this->cbKami->Text = L"Enabled";
				 this->cbKami->UseVisualStyleBackColor = true;
				 this->cbKami->Click += gcnew System::EventHandler(this, &MainForm::cbKami_Click);
				 // 
				 // ddbMode
				 // 
				 this->ddbMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->ddbMode->FormattingEnabled = true;
				 this->ddbMode->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Kill before looting", L"Loot before killing", L"Shortest distance" });
				 this->ddbMode->Location = System::Drawing::Point(92, 89);
				 this->ddbMode->Name = L"ddbMode";
				 this->ddbMode->Size = System::Drawing::Size(148, 21);
				 this->ddbMode->TabIndex = 3;
				 this->ddbMode->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ddbMode_SelectedIndexChanged);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(249, 120);
				 this->Controls->Add(groupBox1);
				 this->Controls->Add(this->ddbMode);
				 this->Controls->Add(gbKami);
				 this->Controls->Add(this->cbKami);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				 this->Name = L"MainForm";
				 this->Text = L"KamiPls";
				 gbKami->ResumeLayout(false);
				 gbKami->PerformLayout();
				 tableLayoutPanel1->ResumeLayout(false);
				 tableLayoutPanel1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudXOffset))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudYOffset))->EndInit();
				 groupBox1->ResumeLayout(false);
				 groupBox1->PerformLayout();
				 tableLayoutPanel2->ResumeLayout(false);
				 tableLayoutPanel2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLootX))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudLootY))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private:
		void cbKami_Click(System::Object^ sender, System::EventArgs^ e);
		void nudXOffset_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		void nudYOffset_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		void nudLootX_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		void nudLootY_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		void ddbMode_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	};
}

