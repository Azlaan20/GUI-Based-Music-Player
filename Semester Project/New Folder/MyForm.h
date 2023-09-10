#pragma once
#include "ProjectHeader.h"

void MarshalString(System::String^ s, std::string& os)
{
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

namespace OOP_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;

		   AudioPlayerv2* Obj1 = new AudioPlayerv2();;
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button10 = (gcnew System::Windows::Forms::Button());
			   this->button11 = (gcnew System::Windows::Forms::Button());
			   this->button12 = (gcnew System::Windows::Forms::Button());
			   this->button13 = (gcnew System::Windows::Forms::Button());
			   this->button14 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(160, 10);
			   this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(677, 142);
			   this->textBox1->TabIndex = 0;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(375, 266);
			   this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(149, 123);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Play";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(546, 266);
			   this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(149, 122);
			   this->button2->TabIndex = 2;
			   this->button2->Text = L"Next";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(13, 342);
			   this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(160, 48);
			   this->button3->TabIndex = 3;
			   this->button3->Text = L"Mount/Unmount";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(11, 10);
			   this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(127, 108);
			   this->button4->TabIndex = 4;
			   this->button4->Text = L"On/Off";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(13, 266);
			   this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(73, 62);
			   this->button5->TabIndex = 5;
			   this->button5->Text = L"CD";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			   // 
			   // button6
			   // 
			   this->button6->Location = System::Drawing::Point(100, 266);
			   this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(73, 62);
			   this->button6->TabIndex = 6;
			   this->button6->Text = L"USB";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(160, 156);
			   this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(677, 98);
			   this->textBox2->TabIndex = 7;
			   this->textBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::textBox2_MouseClick);
			   this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			   // 
			   // button7
			   // 
			   this->button7->Location = System::Drawing::Point(864, 10);
			   this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(233, 45);
			   this->button7->TabIndex = 8;
			   this->button7->Text = L"Create Playlist";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			   // 
			   // button8
			   // 
			   this->button8->Location = System::Drawing::Point(864, 109);
			   this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(233, 45);
			   this->button8->TabIndex = 9;
			   this->button8->Text = L"Add Song";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			   // 
			   // button9
			   // 
			   this->button9->Location = System::Drawing::Point(864, 158);
			   this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(233, 45);
			   this->button9->TabIndex = 10;
			   this->button9->Text = L"Delete Song";
			   this->button9->UseVisualStyleBackColor = true;
			   // 
			   // button10
			   // 
			   this->button10->Location = System::Drawing::Point(864, 258);
			   this->button10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button10->Name = L"button10";
			   this->button10->Size = System::Drawing::Size(233, 45);
			   this->button10->TabIndex = 11;
			   this->button10->Text = L"Shuffle Playlist";
			   this->button10->UseVisualStyleBackColor = true;
			   // 
			   // button11
			   // 
			   this->button11->Location = System::Drawing::Point(864, 307);
			   this->button11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button11->Name = L"button11";
			   this->button11->Size = System::Drawing::Size(233, 45);
			   this->button11->TabIndex = 12;
			   this->button11->Text = L"Play Playlist";
			   this->button11->UseVisualStyleBackColor = true;
			   // 
			   // button12
			   // 
			   this->button12->Location = System::Drawing::Point(864, 59);
			   this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button12->Name = L"button12";
			   this->button12->Size = System::Drawing::Size(233, 45);
			   this->button12->TabIndex = 13;
			   this->button12->Text = L"Display Playlists";
			   this->button12->UseVisualStyleBackColor = true;
			   this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			   // 
			   // button13
			   // 
			   this->button13->Location = System::Drawing::Point(864, 208);
			   this->button13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button13->Name = L"button13";
			   this->button13->Size = System::Drawing::Size(233, 45);
			   this->button13->TabIndex = 14;
			   this->button13->Text = L"Display Playlist Songs";
			   this->button13->UseVisualStyleBackColor = true;
			   // 
			   // button14
			   // 
			   this->button14->Location = System::Drawing::Point(864, 357);
			   this->button14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button14->Name = L"button14";
			   this->button14->Size = System::Drawing::Size(233, 45);
			   this->button14->TabIndex = 15;
			   this->button14->Text = L"Enter";
			   this->button14->UseVisualStyleBackColor = true;
			   this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1120, 414);
			   this->Controls->Add(this->button14);
			   this->Controls->Add(this->button13);
			   this->Controls->Add(this->button12);
			   this->Controls->Add(this->button11);
			   this->Controls->Add(this->button10);
			   this->Controls->Add(this->button9);
			   this->Controls->Add(this->button8);
			   this->Controls->Add(this->button7);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->button6);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->button4);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox1);
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Name = L"MyForm";
			   this->Text = L"AUDIO PLAYER";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   bool x, Playing, Power, Mount;
		   int Enter;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Power = Obj1->ChangePower();
		if (Power == true)
		{
			textBox1->Text = "POWERED ON";
		}
		else
		{
			textBox1->Text = "POWERED OFF";
			Obj1->StopSong();
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //PLAY
		if (!Mount)
		{
			textBox1->Text = "MEDIA NOT MOUNTED. PLEASE MOUNT TO PLAY";
		}
		if (!Power)
		{
			textBox1->Text = "POWER NOT ON. PLEASE TURN ON THE PLAYER";
		}
		if (Mount && Power)
		{
			string output = Obj1->DisplayTitle();
			textBox1->Text = gcnew System::String(output.c_str());
			if (!(Obj1->EndOfFile))
			{
				Playing = Obj1->PlayAudio();
			}
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { //USB
		Obj1->SelectMedia(2);
		textBox1->Text = "PRESS THE MOUNT BUTTON TO MOUNT THE USB";
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { //CD
		Obj1->SelectMedia(1);
		textBox1->Text = "PRESS THE MOUNT BUTTON TO MOUNT THE CD";
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Mount = Obj1->CheckMount();
		if (Mount == true)
		{
			textBox1->Text = "MEDIA MOUNTED";
		}
		else
		{
			textBox1->Text = "MEDIA UNMOUNTED";
		}
		Obj1->TitleToArray();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //NEXT
		Obj1->StopSong();
		string nextoutput = Obj1->DisplayTitle();
		textBox1->Text = (gcnew String(nextoutput.c_str()));
		if (!(Obj1->EndOfFile))
		{
			Playing = Obj1->PlayAudio();
		}
		else
		{
			Obj1->EndOfFile = false;
			Obj1->ADisplayCount = 2;
			Obj1->PlayCount = 2;
			string output = Obj1->DisplayTitle();
			textBox1->Text = gcnew System::String(output.c_str());
			Playing = Obj1->PlayAudio();
		}
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { //CREATE PL
		textBox2->Text = "";
		textBox1->Text = "ENTER THE NAME OF YOUR PLAYLIST IN THE TEXTBOX BELOW";
		Enter = 1; 
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { //DISPLAY PLs
		string Display = Obj1->DisplayPlayLists();
		textBox1->Text = gcnew System::String(Display.c_str());
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { //ENTER
		string Para;
		
		switch (Enter)
		{
		case 1:
			MarshalString(textBox2->Text, Para);
			Obj1->CreatePlayList(Para);
			Enter = 0;
			break;
		case 2:
			MarshalString(textBox2->Text, Para);
			int x = stoi(Para);
			Obj1->AddSong(x);
			Enter = 0;
			break;
		}
	}

	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { //ADD SONG
		string Display = Obj1->DisplayPlayLists();
		textBox1->Text = gcnew System::String(Display.c_str()); //FIRST DISPLAY PLs

		textBox2->Text = "Enter the playlist to which you want to add a song";
		Enter = 2; //Add
	}

	private: System::Void textBox2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		textBox2->Text = "";
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}