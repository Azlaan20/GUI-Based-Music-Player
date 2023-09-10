#pragma once
#include "Code.h"
#include<string>

Song S;
AudioPlayer AP;
AudioPlayerV2 APV2;
AudioPlayerV2 Test;
static int play_pause = 0;
static int mount_unmount = 0;
static int No_of_Playlist=0;
static int SearchButtonClick = 0;
bool createplaylist = false;



namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	void StringConvert(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

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


	protected:

	private: System::Windows::Forms::PictureBox^ Background;
	private: System::Windows::Forms::PictureBox^ PlayButtonFile;


	private: System::Windows::Forms::Button^ ON;


	private: System::Windows::Forms::Button^ OFF;

	private: System::Windows::Forms::TextBox^ Source;



	private: System::Windows::Forms::TextBox^ SearchBar;
	private: System::Windows::Forms::TextBox^ FreeSpace;
	private: System::Windows::Forms::Button^ RepeatButton;
	private: System::Windows::Forms::Button^ ShuffleFile;




	private: System::Windows::Forms::PictureBox^ NextButtonFile;


	private: System::Windows::Forms::Button^ File_Mode;
	private: System::Windows::Forms::Button^ Playlist_Mode;
	private: System::Windows::Forms::PictureBox^ PreviousButtonFile;



	private: System::Windows::Forms::TextBox^ ManufacturerName;
	private: System::Windows::Forms::TextBox^ ModelNumber;
	private: System::Windows::Forms::Button^ AddtoPlaylist;
	private: System::Windows::Forms::Button^ Mount_UnMount;
	private: System::Windows::Forms::PictureBox^ PlayButtonPlaylist;
	private: System::Windows::Forms::PictureBox^ PauseButtonFile;
	private: System::Windows::Forms::PictureBox^ PauseButtonPlaylist;
	private: System::Windows::Forms::PictureBox^ NextButtonPlaylist;
	private: System::Windows::Forms::PictureBox^ PreviousSongPlaylist;
	private: System::Windows::Forms::PictureBox^ SaveIcon;
	private: System::Windows::Forms::TextBox^ SavePlaylist;
	private: System::Windows::Forms::PictureBox^ DeleteIcon;
	private: System::Windows::Forms::PictureBox^ LoadPlaylistIcon;
	private: System::Windows::Forms::TextBox^ LoadPlaylist;

	private: System::Windows::Forms::Button^ CreatePlaylist;
	private: System::Windows::Forms::Button^ RemoveSong;

	private: System::Windows::Forms::Button^ None;
	private: System::Windows::Forms::Button^ VideoPlayer;
	private: System::Windows::Forms::TextBox^ PlaylistName;


	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Button^ SearchButton;

	private: System::Windows::Forms::TextBox^ SearchResult1;
	private: System::Windows::Forms::Button^ Display;
















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Background = (gcnew System::Windows::Forms::PictureBox());
			this->PlayButtonFile = (gcnew System::Windows::Forms::PictureBox());
			this->ON = (gcnew System::Windows::Forms::Button());
			this->OFF = (gcnew System::Windows::Forms::Button());
			this->Source = (gcnew System::Windows::Forms::TextBox());
			this->SearchBar = (gcnew System::Windows::Forms::TextBox());
			this->FreeSpace = (gcnew System::Windows::Forms::TextBox());
			this->RepeatButton = (gcnew System::Windows::Forms::Button());
			this->ShuffleFile = (gcnew System::Windows::Forms::Button());
			this->NextButtonFile = (gcnew System::Windows::Forms::PictureBox());
			this->File_Mode = (gcnew System::Windows::Forms::Button());
			this->Playlist_Mode = (gcnew System::Windows::Forms::Button());
			this->PreviousButtonFile = (gcnew System::Windows::Forms::PictureBox());
			this->ManufacturerName = (gcnew System::Windows::Forms::TextBox());
			this->ModelNumber = (gcnew System::Windows::Forms::TextBox());
			this->AddtoPlaylist = (gcnew System::Windows::Forms::Button());
			this->Mount_UnMount = (gcnew System::Windows::Forms::Button());
			this->PlayButtonPlaylist = (gcnew System::Windows::Forms::PictureBox());
			this->PauseButtonFile = (gcnew System::Windows::Forms::PictureBox());
			this->PauseButtonPlaylist = (gcnew System::Windows::Forms::PictureBox());
			this->NextButtonPlaylist = (gcnew System::Windows::Forms::PictureBox());
			this->PreviousSongPlaylist = (gcnew System::Windows::Forms::PictureBox());
			this->SaveIcon = (gcnew System::Windows::Forms::PictureBox());
			this->SavePlaylist = (gcnew System::Windows::Forms::TextBox());
			this->DeleteIcon = (gcnew System::Windows::Forms::PictureBox());
			this->LoadPlaylistIcon = (gcnew System::Windows::Forms::PictureBox());
			this->LoadPlaylist = (gcnew System::Windows::Forms::TextBox());
			this->CreatePlaylist = (gcnew System::Windows::Forms::Button());
			this->RemoveSong = (gcnew System::Windows::Forms::Button());
			this->None = (gcnew System::Windows::Forms::Button());
			this->VideoPlayer = (gcnew System::Windows::Forms::Button());
			this->PlaylistName = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SearchResult1 = (gcnew System::Windows::Forms::TextBox());
			this->Display = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButtonFile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButtonFile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousButtonFile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButtonPlaylist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButtonFile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButtonPlaylist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButtonPlaylist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousSongPlaylist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaveIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadPlaylistIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// Background
			// 
			this->Background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Background.Image")));
			this->Background->Location = System::Drawing::Point(35, 12);
			this->Background->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Background->Name = L"Background";
			this->Background->Size = System::Drawing::Size(751, 698);
			this->Background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background->TabIndex = 2;
			this->Background->TabStop = false;
			this->Background->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// PlayButtonFile
			// 
			this->PlayButtonFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PlayButtonFile.Image")));
			this->PlayButtonFile->Location = System::Drawing::Point(364, 462);
			this->PlayButtonFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PlayButtonFile->Name = L"PlayButtonFile";
			this->PlayButtonFile->Size = System::Drawing::Size(59, 57);
			this->PlayButtonFile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PlayButtonFile->TabIndex = 3;
			this->PlayButtonFile->TabStop = false;
			this->PlayButtonFile->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// ON
			// 
			this->ON->Location = System::Drawing::Point(69, 42);
			this->ON->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ON->Name = L"ON";
			this->ON->Size = System::Drawing::Size(61, 30);
			this->ON->TabIndex = 4;
			this->ON->Text = L"ON";
			this->ON->UseVisualStyleBackColor = true;
			this->ON->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// OFF
			// 
			this->OFF->Location = System::Drawing::Point(69, 97);
			this->OFF->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->OFF->Name = L"OFF";
			this->OFF->Size = System::Drawing::Size(61, 30);
			this->OFF->TabIndex = 5;
			this->OFF->Text = L"OFF";
			this->OFF->UseVisualStyleBackColor = true;
			this->OFF->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// Source
			// 
			this->Source->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Source->Location = System::Drawing::Point(69, 304);
			this->Source->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Source->Multiline = true;
			this->Source->Name = L"Source";
			this->Source->Size = System::Drawing::Size(137, 43);
			this->Source->TabIndex = 6;
			this->Source->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Source->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// SearchBar
			// 
			this->SearchBar->Location = System::Drawing::Point(567, 409);
			this->SearchBar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchBar->Multiline = true;
			this->SearchBar->Name = L"SearchBar";
			this->SearchBar->Size = System::Drawing::Size(199, 24);
			this->SearchBar->TabIndex = 11;
			this->SearchBar->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// FreeSpace
			// 
			this->FreeSpace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FreeSpace->Location = System::Drawing::Point(35, 614);
			this->FreeSpace->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FreeSpace->Multiline = true;
			this->FreeSpace->Name = L"FreeSpace";
			this->FreeSpace->Size = System::Drawing::Size(137, 43);
			this->FreeSpace->TabIndex = 12;
			this->FreeSpace->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->FreeSpace->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// RepeatButton
			// 
			this->RepeatButton->Location = System::Drawing::Point(448, 576);
			this->RepeatButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RepeatButton->Name = L"RepeatButton";
			this->RepeatButton->Size = System::Drawing::Size(71, 32);
			this->RepeatButton->TabIndex = 13;
			this->RepeatButton->Text = L"Repeat";
			this->RepeatButton->UseVisualStyleBackColor = true;
			this->RepeatButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// ShuffleFile
			// 
			this->ShuffleFile->Location = System::Drawing::Point(269, 576);
			this->ShuffleFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShuffleFile->Name = L"ShuffleFile";
			this->ShuffleFile->Size = System::Drawing::Size(71, 32);
			this->ShuffleFile->TabIndex = 14;
			this->ShuffleFile->Text = L"Shuffle";
			this->ShuffleFile->UseVisualStyleBackColor = true;
			this->ShuffleFile->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// NextButtonFile
			// 
			this->NextButtonFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NextButtonFile.Image")));
			this->NextButtonFile->Location = System::Drawing::Point(477, 470);
			this->NextButtonFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->NextButtonFile->Name = L"NextButtonFile";
			this->NextButtonFile->Size = System::Drawing::Size(41, 36);
			this->NextButtonFile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->NextButtonFile->TabIndex = 15;
			this->NextButtonFile->TabStop = false;
			this->NextButtonFile->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// File_Mode
			// 
			this->File_Mode->Location = System::Drawing::Point(653, 28);
			this->File_Mode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->File_Mode->Name = L"File_Mode";
			this->File_Mode->Size = System::Drawing::Size(112, 32);
			this->File_Mode->TabIndex = 16;
			this->File_Mode->Text = L"File Mode";
			this->File_Mode->UseVisualStyleBackColor = true;
			this->File_Mode->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// Playlist_Mode
			// 
			this->Playlist_Mode->Location = System::Drawing::Point(653, 66);
			this->Playlist_Mode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Playlist_Mode->Name = L"Playlist_Mode";
			this->Playlist_Mode->Size = System::Drawing::Size(111, 32);
			this->Playlist_Mode->TabIndex = 17;
			this->Playlist_Mode->Text = L"PlayList Mode";
			this->Playlist_Mode->UseVisualStyleBackColor = true;
			this->Playlist_Mode->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// PreviousButtonFile
			// 
			this->PreviousButtonFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PreviousButtonFile.Image")));
			this->PreviousButtonFile->Location = System::Drawing::Point(269, 470);
			this->PreviousButtonFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PreviousButtonFile->Name = L"PreviousButtonFile";
			this->PreviousButtonFile->Size = System::Drawing::Size(39, 34);
			this->PreviousButtonFile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PreviousButtonFile->TabIndex = 18;
			this->PreviousButtonFile->TabStop = false;
			this->PreviousButtonFile->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// ManufacturerName
			// 
			this->ManufacturerName->Location = System::Drawing::Point(191, 25);
			this->ManufacturerName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ManufacturerName->Multiline = true;
			this->ManufacturerName->Name = L"ManufacturerName";
			this->ManufacturerName->Size = System::Drawing::Size(183, 36);
			this->ManufacturerName->TabIndex = 19;
			this->ManufacturerName->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// ModelNumber
			// 
			this->ModelNumber->Location = System::Drawing::Point(433, 25);
			this->ModelNumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ModelNumber->Name = L"ModelNumber";
			this->ModelNumber->Size = System::Drawing::Size(163, 22);
			this->ModelNumber->TabIndex = 20;
			this->ModelNumber->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// AddtoPlaylist
			// 
			this->AddtoPlaylist->Location = System::Drawing::Point(69, 425);
			this->AddtoPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AddtoPlaylist->Name = L"AddtoPlaylist";
			this->AddtoPlaylist->Size = System::Drawing::Size(117, 31);
			this->AddtoPlaylist->TabIndex = 21;
			this->AddtoPlaylist->Text = L"Add to Playlist";
			this->AddtoPlaylist->UseVisualStyleBackColor = true;
			this->AddtoPlaylist->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// Mount_UnMount
			// 
			this->Mount_UnMount->Location = System::Drawing::Point(92, 183);
			this->Mount_UnMount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Mount_UnMount->Name = L"Mount_UnMount";
			this->Mount_UnMount->Size = System::Drawing::Size(79, 41);
			this->Mount_UnMount->TabIndex = 22;
			this->Mount_UnMount->Text = L"Mount/UnMount";
			this->Mount_UnMount->UseVisualStyleBackColor = true;
			this->Mount_UnMount->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// PlayButtonPlaylist
			// 
			this->PlayButtonPlaylist->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PlayButtonPlaylist.Image")));
			this->PlayButtonPlaylist->Location = System::Drawing::Point(364, 462);
			this->PlayButtonPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PlayButtonPlaylist->Name = L"PlayButtonPlaylist";
			this->PlayButtonPlaylist->Size = System::Drawing::Size(59, 57);
			this->PlayButtonPlaylist->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PlayButtonPlaylist->TabIndex = 23;
			this->PlayButtonPlaylist->TabStop = false;
			this->PlayButtonPlaylist->Click += gcnew System::EventHandler(this, &MyForm::PlayButtonPlaylist_Click);
			// 
			// PauseButtonFile
			// 
			this->PauseButtonFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PauseButtonFile.Image")));
			this->PauseButtonFile->Location = System::Drawing::Point(364, 462);
			this->PauseButtonFile->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PauseButtonFile->Name = L"PauseButtonFile";
			this->PauseButtonFile->Size = System::Drawing::Size(59, 57);
			this->PauseButtonFile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PauseButtonFile->TabIndex = 24;
			this->PauseButtonFile->TabStop = false;
			this->PauseButtonFile->Click += gcnew System::EventHandler(this, &MyForm::PauseButtonFile_Click);
			// 
			// PauseButtonPlaylist
			// 
			this->PauseButtonPlaylist->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PauseButtonPlaylist.Image")));
			this->PauseButtonPlaylist->Location = System::Drawing::Point(364, 462);
			this->PauseButtonPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PauseButtonPlaylist->Name = L"PauseButtonPlaylist";
			this->PauseButtonPlaylist->Size = System::Drawing::Size(59, 57);
			this->PauseButtonPlaylist->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PauseButtonPlaylist->TabIndex = 25;
			this->PauseButtonPlaylist->TabStop = false;
			this->PauseButtonPlaylist->Click += gcnew System::EventHandler(this, &MyForm::PauseButtonPlaylist_Click);
			// 
			// NextButtonPlaylist
			// 
			this->NextButtonPlaylist->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NextButtonPlaylist.Image")));
			this->NextButtonPlaylist->Location = System::Drawing::Point(477, 471);
			this->NextButtonPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->NextButtonPlaylist->Name = L"NextButtonPlaylist";
			this->NextButtonPlaylist->Size = System::Drawing::Size(41, 36);
			this->NextButtonPlaylist->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->NextButtonPlaylist->TabIndex = 26;
			this->NextButtonPlaylist->TabStop = false;
			this->NextButtonPlaylist->Click += gcnew System::EventHandler(this, &MyForm::NextButtonPlaylist_Click);
			// 
			// PreviousSongPlaylist
			// 
			this->PreviousSongPlaylist->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PreviousSongPlaylist.Image")));
			this->PreviousSongPlaylist->Location = System::Drawing::Point(269, 471);
			this->PreviousSongPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PreviousSongPlaylist->Name = L"PreviousSongPlaylist";
			this->PreviousSongPlaylist->Size = System::Drawing::Size(39, 34);
			this->PreviousSongPlaylist->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PreviousSongPlaylist->TabIndex = 27;
			this->PreviousSongPlaylist->TabStop = false;
			this->PreviousSongPlaylist->Click += gcnew System::EventHandler(this, &MyForm::PreviousSongPlaylist_Click);
			// 
			// SaveIcon
			// 
			this->SaveIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveIcon.Image")));
			this->SaveIcon->Location = System::Drawing::Point(177, 624);
			this->SaveIcon->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SaveIcon->Name = L"SaveIcon";
			this->SaveIcon->Size = System::Drawing::Size(37, 32);
			this->SaveIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SaveIcon->TabIndex = 28;
			this->SaveIcon->TabStop = false;
			this->SaveIcon->Click += gcnew System::EventHandler(this, &MyForm::SaveIcon_Click);
			// 
			// SavePlaylist
			// 
			this->SavePlaylist->Location = System::Drawing::Point(220, 633);
			this->SavePlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SavePlaylist->Multiline = true;
			this->SavePlaylist->Name = L"SavePlaylist";
			this->SavePlaylist->Size = System::Drawing::Size(161, 24);
			this->SavePlaylist->TabIndex = 29;
			this->SavePlaylist->Text = L"Save Playlist. Press Icon";
			// 
			// DeleteIcon
			// 
			this->DeleteIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteIcon.Image")));
			this->DeleteIcon->Location = System::Drawing::Point(695, 193);
			this->DeleteIcon->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DeleteIcon->Name = L"DeleteIcon";
			this->DeleteIcon->Size = System::Drawing::Size(37, 43);
			this->DeleteIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->DeleteIcon->TabIndex = 30;
			this->DeleteIcon->TabStop = false;
			this->DeleteIcon->Click += gcnew System::EventHandler(this, &MyForm::DeleteIcon_Click);
			// 
			// LoadPlaylistIcon
			// 
			this->LoadPlaylistIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadPlaylistIcon.Image")));
			this->LoadPlaylistIcon->Location = System::Drawing::Point(35, 576);
			this->LoadPlaylistIcon->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LoadPlaylistIcon->Name = L"LoadPlaylistIcon";
			this->LoadPlaylistIcon->Size = System::Drawing::Size(37, 32);
			this->LoadPlaylistIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->LoadPlaylistIcon->TabIndex = 31;
			this->LoadPlaylistIcon->TabStop = false;
			this->LoadPlaylistIcon->Click += gcnew System::EventHandler(this, &MyForm::LoadPlaylistIcon_Click);
			// 
			// LoadPlaylist
			// 
			this->LoadPlaylist->Location = System::Drawing::Point(77, 583);
			this->LoadPlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LoadPlaylist->Multiline = true;
			this->LoadPlaylist->Name = L"LoadPlaylist";
			this->LoadPlaylist->Size = System::Drawing::Size(161, 24);
			this->LoadPlaylist->TabIndex = 32;
			this->LoadPlaylist->Text = L"Load Playlist. Press Icon";
			this->LoadPlaylist->TextChanged += gcnew System::EventHandler(this, &MyForm::LoadPlaylist_TextChanged);
			// 
			// CreatePlaylist
			// 
			this->CreatePlaylist->Location = System::Drawing::Point(69, 462);
			this->CreatePlaylist->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CreatePlaylist->Name = L"CreatePlaylist";
			this->CreatePlaylist->Size = System::Drawing::Size(117, 31);
			this->CreatePlaylist->TabIndex = 33;
			this->CreatePlaylist->Text = L"Create Playlist";
			this->CreatePlaylist->UseVisualStyleBackColor = true;
			this->CreatePlaylist->Click += gcnew System::EventHandler(this, &MyForm::CreatePlaylist_Click);
			// 
			// RemoveSong
			// 
			this->RemoveSong->Location = System::Drawing::Point(69, 498);
			this->RemoveSong->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RemoveSong->Name = L"RemoveSong";
			this->RemoveSong->Size = System::Drawing::Size(117, 30);
			this->RemoveSong->TabIndex = 35;
			this->RemoveSong->Text = L"Remove Song";
			this->RemoveSong->UseVisualStyleBackColor = true;
			this->RemoveSong->Click += gcnew System::EventHandler(this, &MyForm::RemoveSong_Click);
			// 
			// None
			// 
			this->None->Location = System::Drawing::Point(364, 576);
			this->None->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->None->Name = L"None";
			this->None->Size = System::Drawing::Size(59, 32);
			this->None->TabIndex = 37;
			this->None->Text = L"None";
			this->None->UseVisualStyleBackColor = true;
			this->None->Click += gcnew System::EventHandler(this, &MyForm::None_Click);
			// 
			// VideoPlayer
			// 
			this->VideoPlayer->Location = System::Drawing::Point(653, 103);
			this->VideoPlayer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VideoPlayer->Name = L"VideoPlayer";
			this->VideoPlayer->Size = System::Drawing::Size(111, 32);
			this->VideoPlayer->TabIndex = 38;
			this->VideoPlayer->Text = L"Video";
			this->VideoPlayer->UseVisualStyleBackColor = true;
			this->VideoPlayer->Click += gcnew System::EventHandler(this, &MyForm::VideoPlayer_Click);
			// 
			// PlaylistName
			// 
			this->PlaylistName->Hide();
			this->PlaylistName->Location = System::Drawing::Point(321, 251);
			this->PlaylistName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PlaylistName->Multiline = true;
			this->PlaylistName->Name = L"PlaylistName";
			this->PlaylistName->Size = System::Drawing::Size(199, 29);
			this->PlaylistName->TabIndex = 39;
			this->PlaylistName->TextChanged += gcnew System::EventHandler(this, &MyForm::PlaylistName_TextChanged);
			// 
			// Enter
			// 
			this->Enter->Hide();
			this->Enter->Location = System::Drawing::Point(348, 303);
			this->Enter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(115, 28);
			this->Enter->TabIndex = 42;
			this->Enter->Text = L"Enter";
			this->Enter->UseVisualStyleBackColor = true;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(609, 439);
			this->SearchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(113, 31);
			this->SearchButton->TabIndex = 43;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm::SearchButton_Click);
			// 
			// SearchResult1
			// 
			this->SearchResult1->Hide();
			this->SearchResult1->Location = System::Drawing::Point(231, 313);
			this->SearchResult1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchResult1->Multiline = true;
			this->SearchResult1->Name = L"SearchResult1";
			this->SearchResult1->Size = System::Drawing::Size(108, 51);
			this->SearchResult1->TabIndex = 44;
			this->SearchResult1->TextChanged += gcnew System::EventHandler(this, &MyForm::SearchResult1_TextChanged);
			// 
			// Display
			// 
			this->Display->Location = System::Drawing::Point(683, 309);
			this->Display->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Display->Name = L"Display";
			this->Display->Size = System::Drawing::Size(92, 37);
			this->Display->TabIndex = 45;
			this->Display->Text = L"Display";
			this->Display->UseVisualStyleBackColor = true;
			this->Display->Click += gcnew System::EventHandler(this, &MyForm::Display_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 660);
			this->Controls->Add(this->Display);
			this->Controls->Add(this->SearchResult1);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->PlaylistName);
			this->Controls->Add(this->VideoPlayer);
			this->Controls->Add(this->None);
			this->Controls->Add(this->RemoveSong);
			this->Controls->Add(this->CreatePlaylist);
			this->Controls->Add(this->LoadPlaylist);
			this->Controls->Add(this->LoadPlaylistIcon);
			this->Controls->Add(this->DeleteIcon);
			this->Controls->Add(this->SavePlaylist);
			this->Controls->Add(this->SaveIcon);
			this->Controls->Add(this->Mount_UnMount);
			this->Controls->Add(this->AddtoPlaylist);
			this->Controls->Add(this->ModelNumber);
			this->Controls->Add(this->ManufacturerName);
			this->Controls->Add(this->PreviousButtonFile);
			this->Controls->Add(this->Playlist_Mode);
			this->Controls->Add(this->File_Mode);
			this->Controls->Add(this->NextButtonFile);
			this->Controls->Add(this->ShuffleFile);
			this->Controls->Add(this->RepeatButton);
			this->Controls->Add(this->FreeSpace);
			this->Controls->Add(this->SearchBar);
			this->Controls->Add(this->Source);
			this->Controls->Add(this->OFF);
			this->Controls->Add(this->ON);
			this->Controls->Add(this->PlayButtonFile);
			this->Controls->Add(this->PauseButtonFile);
			this->Controls->Add(this->PauseButtonPlaylist);
			this->Controls->Add(this->PlayButtonPlaylist);
			this->Controls->Add(this->NextButtonPlaylist);
			this->Controls->Add(this->PreviousSongPlaylist);
			this->Controls->Add(this->Background);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButtonFile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButtonFile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousButtonFile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButtonPlaylist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButtonFile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButtonPlaylist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButtonPlaylist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousSongPlaylist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaveIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeleteIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadPlaylistIcon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		PlayButtonFile->Hide();
		PauseButtonFile->Show();

		S.Resume_Song();
	}

private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	S.TurnOn();
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	S.Close_Songlist();
	S.TurnOff();
	exit(EXIT_FAILURE);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	
private: System::Void button8_Click(System::Object ^ sender, System::EventArgs ^ e) {
	APV2.CurrentSong = S.CurrentSong;
	APV2.addSong();
}
	     
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	S.TurnOnRepeat();
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	S.TurnOnShuffle();
}

private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	
		S.Next_Songlist();
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	S.Pause_Songlist();
	APV2.FileMode = true;
	APV2.PlaylistMode = false;
	

	
		this->PlayButtonPlaylist->Hide();
		this->PlayButtonFile->Show();
		this->PauseButtonPlaylist->Hide();
		this->PauseButtonFile->Show();
		this->NextButtonPlaylist->Hide();
		this->NextButtonFile->Show();
		this->PreviousSongPlaylist->Hide();
		this->PreviousButtonFile->Show();

}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	S.Pause_Songlist();

	if (No_of_Playlist >= 1)
	{
		APV2.FileMode = false;
		APV2.PlaylistMode = true;


		this->PlayButtonPlaylist->Show();
		this->PlayButtonFile->Hide();
		this->PauseButtonPlaylist->Show();
		this->PauseButtonFile->Hide();
		this->NextButtonPlaylist->Show();
		this->NextButtonFile->Hide();
		this->PreviousSongPlaylist->Show();
		this->PreviousButtonFile->Hide();
	}

}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {	
		S.Previous_Songlist();
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e){
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	++mount_unmount;

	AP.CheckDriveType();
	AP.CheckDriveFreeSpace();

	if (AP.totalstorage <= 16)
	{
		FreeSpace->Text = "Free Space:\n";
		FreeSpace->Text = AP.freestorage + "/" + AP.totalstorage + "GB";
	}

	else if (AP.totalstorage > 16)
	{
		FreeSpace->Text = "Exceeding Compatible Storage Capacity.\n";
		exit(EXIT_FAILURE);
	}


	if (AP.getCheck() == 2)
	{
		Source->Text = "USB";
	}

	else if (AP.getCheck() == 5)
	{
		Source->Text = "CD-ROM";
	}

	else
	{
		Source->Text = "Incorrect File Format";
	}

	ManufacturerName->Text = "Manufacturer Name: SONY";
	ModelNumber->Text = "Model Number: 12B13";
	S.AddSongsFromFile();


	if (mount_unmount % 2 != 0)
	{
		S.Play_Songlist(S.Songlist[0]);
	}

	else if (mount_unmount % 2 == 0)
	{
		S.Pause_Songlist();
	}
}
private: System::Void PlayButtonPlaylist_Click(System::Object^ sender, System::EventArgs^ e) {
	this->PlayButtonPlaylist->Hide();
	this->PauseButtonPlaylist->Show();

	APV2.ResumeSong_Playlist();
}
private: System::Void PauseButtonFile_Click(System::Object^ sender, System::EventArgs^ e) {
	this->PauseButtonFile->Hide();
	this->PlayButtonFile->Show();
	APV2.PauseSong_Playlist();
}
private: System::Void NextButtonPlaylist_Click(System::Object^ sender, System::EventArgs^ e) {
	APV2.NextSong_Playlist();
}
private: System::Void PreviousSongPlaylist_Click(System::Object^ sender, System::EventArgs^ e) {
	APV2.PreviousSong_Playlist();

}
private: System::Void SavePlaylist_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SaveIcon_Click(System::Object^ sender, System::EventArgs^ e) {
	APV2.savePlaylist();
}

private: System::Void LoadPlaylist_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LoadPlaylistIcon_Click(System::Object^ sender, System::EventArgs^ e) {
	Test.loadPlaylist();
	Test.savePlaylist();
}

private: System::Void CreatePlaylist_Click(System::Object^ sender, System::EventArgs^ e) {
	++No_of_Playlist;
	if (No_of_Playlist % 2 != 0)
	{
		PlaylistName->Show();
		Enter->Show();
		createplaylist = true;
	}

	else
	{
		PlaylistName->Hide();
		Enter->Hide();
		createplaylist = false;
	}
}
private: System::Void RemoveSong_Click(System::Object^ sender, System::EventArgs^ e) {
	APV2.removeSong();
}
private: System::Void None_Click(System::Object^ sender, System::EventArgs^ e) {
	S.Shuffle = false;
	S.Repeat = false;
}
private: System::Void PauseButtonPlaylist_Click(System::Object^ sender, System::EventArgs^ e) {
	this->PauseButtonPlaylist->Hide();
	this->PlayButtonPlaylist->Show();
	APV2.PauseSong_Playlist();
}

private: System::Void DeleteIcon_Click(System::Object^ sender, System::EventArgs^ e) {
	APV2.deletePlaylist();
}
private: System::Void VideoPlayer_Click(System::Object^ sender, System::EventArgs^ e) {
	S.Close_Songlist();
	APV2.FileMode = false;
	APV2.PlaylistMode = false;

	S.Play_Songlist(S.Videolist[0]);
}
private: System::Void PlaylistName_TextChanged(System::Object^ sender, System::EventArgs^ e) {	
}

private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ S = PlaylistName->Text;
	string song;

	StringConvert(S, song);

	APV2.createNewPlaylist(song);
	PlaylistName->Hide();
	Enter->Hide();
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
	++SearchButtonClick;

	if (SearchButtonClick % 2 != 0)
	{
		SearchResult1->Show();
		String^ s = SearchBar->Text;
		string song;
		string Result;

		StringConvert(s, song);

		if (APV2.FileMode == true && APV2.PlaylistMode == false)
		{
			S.Search(song);

			if (S.Search(song))
			{
				Result = "File Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;

			}

			else if (!S.Search(song))
			{
				Result = "File Not Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;
			}
		}

		else if (APV2.FileMode == false && APV2.PlaylistMode == false)
		{
			S.Search(song);
			if (S.Search(song) == 0)
			{
				Result = "File Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;

			}

			else
			{
				Result = "File Not Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;
			}

		}

		else if (APV2.FileMode == false && APV2.PlaylistMode == true)
		{
			APV2.searchPlaylist(song);
			APV2.Search(song);
			if (APV2.Search(song) == 0)
			{
				Result = "File Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;

			}

			else
			{
				Result = "File Not Found";
				String^ str2 = gcnew String(Result.c_str());

				SearchResult1->Text = str2;
			}
		}
	}

	else if (SearchButtonClick % 2 == 0)
	{
		SearchResult1->Hide();
	}
}

private: System::Void SearchResult1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Display_Click(System::Object^ sender, System::EventArgs^ e) {

	//String^ Songs;

	//if (APV2.FileMode == true && APV2.PlaylistMode==false)
	//{
		S.DisplayFile();

		/*StringConvert(Songs, S.DisplayFile());

		Songlist->Text = Songs;
	}

	else if (APV2.PlaylistMode == true && APV2.FileMode==true)
	{
		APV2.displayPlaylist();
	}*/
}

};
}

