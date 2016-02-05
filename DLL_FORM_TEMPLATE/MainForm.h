#pragma once

#include "unmanaged.h"

#pragma managed

namespace DLL_FORM_TEMPLATE 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Runtime::InteropServices;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			FilesDownloaded = 0;
			InitializeComponent();
		}

	protected:

		~MainForm(void)
		{
			if( components )
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
	private:

		System::Windows::Forms::Timer^	UpdateData_Timer;

		CheckBox^    chkbxSaveMusic;
		GroupBox^    grpbxMain;
		ProgressBar^ progressbar;
		Label^		 lblStatus;
	    Label^       lblGellin;
		IContainer^	 components;

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->chkbxSaveMusic = (gcnew System::Windows::Forms::CheckBox());
			this->UpdateData_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->grpbxMain = (gcnew System::Windows::Forms::GroupBox());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->progressbar = (gcnew System::Windows::Forms::ProgressBar());
			this->lblGellin = (gcnew System::Windows::Forms::Label());
			this->grpbxMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// chkbxSaveMusic
			// 
			this->chkbxSaveMusic->AutoSize = true;
			this->chkbxSaveMusic->BackColor = System::Drawing::Color::Transparent;
			this->chkbxSaveMusic->Checked = true;
			this->chkbxSaveMusic->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkbxSaveMusic->ForeColor = System::Drawing::Color::Black;
			this->chkbxSaveMusic->Location = System::Drawing::Point(44, 22);
			this->chkbxSaveMusic->Name = L"chkbxSaveMusic";
			this->chkbxSaveMusic->Size = System::Drawing::Size(15, 14);
			this->chkbxSaveMusic->TabIndex = 10;
			this->chkbxSaveMusic->UseVisualStyleBackColor = false;
			// 
			// UpdateData_Timer
			// 
			this->UpdateData_Timer->Enabled = true;
			this->UpdateData_Timer->Interval = 500;
			this->UpdateData_Timer->Tick += gcnew System::EventHandler(this, &MainForm::UpdateData_Timer_Tick);
			// 
			// grpbxMain
			// 
			this->grpbxMain->BackColor = System::Drawing::Color::WhiteSmoke;
			this->grpbxMain->Controls->Add(this->lblStatus);
			this->grpbxMain->Controls->Add(this->progressbar);
			this->grpbxMain->Controls->Add(this->chkbxSaveMusic);
			this->grpbxMain->ForeColor = System::Drawing::Color::Black;
			this->grpbxMain->Location = System::Drawing::Point(14, 7);
			this->grpbxMain->Name = L"grpbxMain";
			this->grpbxMain->Size = System::Drawing::Size(171, 86);
			this->grpbxMain->TabIndex = 4;
			this->grpbxMain->TabStop = false;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->BackColor = System::Drawing::Color::Transparent;
			this->lblStatus->ForeColor = System::Drawing::Color::Black;
			this->lblStatus->Location = System::Drawing::Point(42, 68);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(0, 13);
			this->lblStatus->TabIndex = 12;
			this->lblStatus->SizeChanged += gcnew System::EventHandler(this, &MainForm::lblStatus_SizeChanged);
			// 
			// progressbar
			// 
			this->progressbar->Location = System::Drawing::Point(35, 45);
			this->progressbar->Name = L"progressbar";
			this->progressbar->Size = System::Drawing::Size(100, 13);
			this->progressbar->TabIndex = 11;
			// 
			// lblGellin
			// 
			this->lblGellin->AutoSize = true;
			this->lblGellin->BackColor = System::Drawing::Color::Transparent;
			this->lblGellin->ForeColor = System::Drawing::Color::Black;
			this->lblGellin->Location = System::Drawing::Point(33, 98);
			this->lblGellin->Name = L"lblGellin";
			this->lblGellin->Size = System::Drawing::Size(134, 13);
			this->lblGellin->TabIndex = 10;
			this->lblGellin->Text = L"Developed By: Team Zeus";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(199, 116);
			this->Controls->Add(this->lblGellin);
			this->Controls->Add(this->grpbxMain);
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->grpbxMain->ResumeLayout(false);
			this->grpbxMain->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

		Int32 FilesDownloaded;

        Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			 unmanaged->EncryptStrings();

			 Text = gcnew String( unmanaged->szTitle );
			 //lblGellin->Text = gcnew String( unmanaged->szDev );
			 lblStatus->Text = gcnew String( unmanaged->szStatus );
			 grpbxMain->Text = gcnew String( unmanaged->szGrpbx );
			 chkbxSaveMusic->Text = gcnew String( unmanaged->szChkbx );

			 unmanaged->DestroyInitStrings();
			 unmanaged->sGuiCreated = 1;
		}

		Void CenterLabelinGroupbox( Control^ o, Label^ l )
		{
			 Point Pos = l->Location;
			 Pos.X = ( o->Size.Width / 2 ) - ( l->Size.Width / 2 );
			 l->Location = Pos;
		}

	    Void SuspendDrawing(HWND handle)
		{
			::SendMessage( handle, WM_SETREDRAW, (WPARAM)FALSE, NULL );
		}

		Void ResumeDrawing(HWND handle)
		{
			::SendMessage( handle, WM_SETREDRAW, (WPARAM)TRUE, NULL );
		}

        Void DownloadFileCompleted(System::Object ^sender, AsyncCompletedEventArgs ^e)
		{
			progressbar->Value = 0;
			lblStatus->Text = "Download Complete, Waiting";
		}

        Void DownloadProgressChanged(System::Object ^sender, DownloadProgressChangedEventArgs ^e)
		{
			 progressbar->Value = e->ProgressPercentage;
		}

        Void Download(String^ url, String^ Location)
		{
			 WebClient^ _WebClient = gcnew WebClient();
			 _WebClient->DownloadFileCompleted   += gcnew AsyncCompletedEventHandler( this, &MainForm::DownloadFileCompleted );
			 _WebClient->DownloadProgressChanged += gcnew DownloadProgressChangedEventHandler( this, &MainForm::DownloadProgressChanged );
			 _WebClient->DownloadFileAsync( gcnew Uri( url ), Location );
		}

        Void UpdateData_Timer_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			 if( chkbxSaveMusic->Checked )
			 {
				if( unmanaged->isFiletoDownload )
				{
					unmanaged->isFiletoDownload = FALSE;
					FilesDownloaded += 1;

					String^ Location = gcnew String( unmanaged->szLocation );
					String^ SongName/* = gcnew String( unmanaged->szSongName )*/;

					//if( SongName == "" )
						SongName = "Unknown" + FilesDownloaded.ToString();

					if( !Directory::Exists( "C:\\Pandora" ) )
						Directory::CreateDirectory( "C:\\Pandora" );

					Download( Location, "C:\\Pandora\\" + SongName + ".mp4" );

					lblStatus->Text = "File Downloading";
				}
			}
		}	

        Void lblStatus_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			 SuspendDrawing( (HWND)Handle.ToPointer() ); 
			 CenterLabelinGroupbox( grpbxMain, lblStatus );
			 ResumeDrawing( (HWND)Handle.ToPointer() );
			 Refresh();
		}
	};
}

#pragma endregion