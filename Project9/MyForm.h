#pragma once
#include <ctime>
#include "Personaje.h"
#include "Controladora.h"
namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(static_cast<unsigned int>(std::time(0)));
			InitializeComponent();
			//tmrGenerarRecursos->Interval = 2000;
			g = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(g, this->ClientRectangle);
			bmpGuardian = gcnew Bitmap("imagenes/Sprite_Guardian_final.png");
			bmpSemilla = gcnew Bitmap("imagenes/Semillas_Totales.png");
			bmpAgua = gcnew Bitmap("imagenes/Agua_Final.png");
			bmpResiduo = gcnew Bitmap("imagenes/Residuos_Finalr.png");
			bmpfondo = gcnew Bitmap("imagenes/fondooofinallll.jfif");
			


			simulador = new Controlador(bmpGuardian, bmpSemilla, bmpAgua, bmpResiduo);
		}
	private:
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		//bitmap
		Bitmap^ bmpGuardian;
		Controlador* simulador;
		Bitmap^ bmpResiduo;
		Bitmap^ bmpSemilla;
		Bitmap^ bmpAgua;
		Bitmap^ bmpfondo;


	private: System::Windows::Forms::Timer^ tmrMain;
	private: System::Windows::Forms::Timer^ tmrDisparos;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ lblAgua;
	private: System::Windows::Forms::Label^ lblSemilla;
	private: System::Windows::Forms::Label^ lblResiduo;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ lblAuga_Obtenida;
	private: System::Windows::Forms::Label^ lblSemilla_Obtenida;
	private: System::Windows::Forms::Label^ lblResiduo_Obtenido;
	private: System::Windows::Forms::Timer^ tmrGenerarRecursos;
	private: System::Windows::Forms::Label^ lblvidas;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tmrMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblvidas = (gcnew System::Windows::Forms::Label());
			this->tmrDisparos = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->lblAgua = (gcnew System::Windows::Forms::Label());
			this->lblSemilla = (gcnew System::Windows::Forms::Label());
			this->lblResiduo = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->lblAuga_Obtenida = (gcnew System::Windows::Forms::Label());
			this->lblSemilla_Obtenida = (gcnew System::Windows::Forms::Label());
			this->lblResiduo_Obtenido = (gcnew System::Windows::Forms::Label());
			this->tmrGenerarRecursos = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// tmrMain
			// 
			this->tmrMain->Enabled = true;
			this->tmrMain->Tick += gcnew System::EventHandler(this, &MyForm::tmrMain_Tick);
			// 
			// lblvidas
			// 
			this->lblvidas->AutoSize = true;
			this->lblvidas->BackColor = System::Drawing::Color::Transparent;
			this->lblvidas->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblvidas->Location = System::Drawing::Point(12, 23);
			this->lblvidas->Name = L"lblvidas";
			this->lblvidas->Size = System::Drawing::Size(80, 29);
			this->lblvidas->TabIndex = 0;
			this->lblvidas->Text = L"Vidas";
			// 
			// tmrDisparos
			// 
			this->tmrDisparos->Enabled = true;
			this->tmrDisparos->Interval = 1000;
			this->tmrDisparos->Tick += gcnew System::EventHandler(this, &MyForm::tmrDisparos_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(167, 17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(33, 35);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::IndianRed;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(268, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(34, 40);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Black;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(360, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(40, 40);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// lblAgua
			// 
			this->lblAgua->AutoSize = true;
			this->lblAgua->BackColor = System::Drawing::Color::Transparent;
			this->lblAgua->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblAgua->Location = System::Drawing::Point(206, 23);
			this->lblAgua->Name = L"lblAgua";
			this->lblAgua->Size = System::Drawing::Size(46, 17);
			this->lblAgua->TabIndex = 4;
			this->lblAgua->Text = L"label1";
			// 
			// lblSemilla
			// 
			this->lblSemilla->AutoSize = true;
			this->lblSemilla->BackColor = System::Drawing::Color::Transparent;
			this->lblSemilla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblSemilla->Location = System::Drawing::Point(308, 23);
			this->lblSemilla->Name = L"lblSemilla";
			this->lblSemilla->Size = System::Drawing::Size(46, 17);
			this->lblSemilla->TabIndex = 5;
			this->lblSemilla->Text = L"label1";
			// 
			// lblResiduo
			// 
			this->lblResiduo->AutoSize = true;
			this->lblResiduo->BackColor = System::Drawing::Color::Transparent;
			this->lblResiduo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblResiduo->Location = System::Drawing::Point(406, 23);
			this->lblResiduo->Name = L"lblResiduo";
			this->lblResiduo->Size = System::Drawing::Size(46, 17);
			this->lblResiduo->TabIndex = 6;
			this->lblResiduo->Text = L"label1";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(707, 17);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(33, 35);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::IndianRed;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(798, 12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(34, 40);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox5->TabIndex = 8;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Black;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(890, 12);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(40, 40);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 9;
			this->pictureBox6->TabStop = false;
			// 
			// lblAuga_Obtenida
			// 
			this->lblAuga_Obtenida->AutoSize = true;
			this->lblAuga_Obtenida->BackColor = System::Drawing::Color::Transparent;
			this->lblAuga_Obtenida->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblAuga_Obtenida->Location = System::Drawing::Point(746, 23);
			this->lblAuga_Obtenida->Name = L"lblAuga_Obtenida";
			this->lblAuga_Obtenida->Size = System::Drawing::Size(46, 17);
			this->lblAuga_Obtenida->TabIndex = 10;
			this->lblAuga_Obtenida->Text = L"label1";
			// 
			// lblSemilla_Obtenida
			// 
			this->lblSemilla_Obtenida->AutoSize = true;
			this->lblSemilla_Obtenida->BackColor = System::Drawing::Color::Transparent;
			this->lblSemilla_Obtenida->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblSemilla_Obtenida->Location = System::Drawing::Point(838, 23);
			this->lblSemilla_Obtenida->Name = L"lblSemilla_Obtenida";
			this->lblSemilla_Obtenida->Size = System::Drawing::Size(46, 17);
			this->lblSemilla_Obtenida->TabIndex = 11;
			this->lblSemilla_Obtenida->Text = L"label2";
			// 
			// lblResiduo_Obtenido
			// 
			this->lblResiduo_Obtenido->AutoSize = true;
			this->lblResiduo_Obtenido->BackColor = System::Drawing::Color::Transparent;
			this->lblResiduo_Obtenido->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblResiduo_Obtenido->Location = System::Drawing::Point(936, 23);
			this->lblResiduo_Obtenido->Name = L"lblResiduo_Obtenido";
			this->lblResiduo_Obtenido->Size = System::Drawing::Size(46, 17);
			this->lblResiduo_Obtenido->TabIndex = 12;
			this->lblResiduo_Obtenido->Text = L"label3";
			// 
			// tmrGenerarRecursos
			// 
			this->tmrGenerarRecursos->Enabled = true;
			this->tmrGenerarRecursos->Tick += gcnew System::EventHandler(this, &MyForm::tmrGenerarRecursos_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1784, 961);
			this->Controls->Add(this->lblResiduo_Obtenido);
			this->Controls->Add(this->lblSemilla_Obtenida);
			this->Controls->Add(this->lblAuga_Obtenida);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->lblResiduo);
			this->Controls->Add(this->lblSemilla);
			this->Controls->Add(this->lblAgua);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblvidas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::FrmMain_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tmrMain_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (simulador->getDisparar() == true)
		{
			simulador->agregar_disparos();
			simulador->setDisparar(false);
		}

		//clear 
		buffer->Graphics->Clear(Color::White);
		
		//colision
		simulador->colision(buffer->Graphics);

		//mover
		simulador->mover_elementos(buffer->Graphics);

		//dibuja en pantalla
		buffer->Graphics->DrawImage(bmpfondo, 0, 0, this->Width, this->Height);
		simulador->dibujar_elementos(buffer->Graphics, bmpGuardian, bmpSemilla, bmpAgua, bmpResiduo);

		// elementos
		lblvidas->Text = "Vidas: " + simulador->getGuardian()->getVidas();
		lblSemilla->Text = Convert::ToString(simulador->getN_Semillas());
		lblAgua->Text = Convert::ToString(simulador->getN_Agua());
		lblResiduo->Text = Convert::ToString(simulador->getN_Residuo());

		lblSemilla_Obtenida->Text = Convert::ToString(simulador->getCount_Semilla());
		lblAuga_Obtenida->Text = Convert::ToString(simulador->getCount_Agua());
		lblResiduo_Obtenido->Text = Convert::ToString(simulador->getCount_Residuo());

		if (simulador->getTiempo_disparo() == 0)
		{
			simulador->setTiempo_disparo(1);
		}

		buffer->Render(g);
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		switch (e->KeyCode)
		{
		case Keys::Left: simulador->getGuardian()->mover(buffer->Graphics, 'A'); break;
		case Keys::Right: simulador->getGuardian()->mover(buffer->Graphics, 'D'); break;
		case Keys::Up: simulador->getGuardian()->mover(buffer->Graphics, 'W'); break;
		case Keys::Down: simulador->getGuardian()->mover(buffer->Graphics, 'S'); break;
		case Keys::Space:
			if (simulador->getCount_Agua() >= 1 && simulador->getCount_Residuo() >= 1 && simulador->getCount_Semilla() >= 1 && simulador->getTiempo_disparo() == 1)
			{
				simulador->setDisparar(true);
				simulador->setTiempo_disparo(0);

				simulador->disminuirAgua();
				simulador->disminuirResiduo();
				simulador->disminuirSemilla();
			}
			else
			{
				MessageBox::Show("no tiene recursos suficientes");
			}
			break;
		}
	}
	private: System::Void tmrDisparos_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		simulador->disminuir_tiempo();
	}
	private: System::Void tmrGenerarRecursos_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		simulador->agragarElementos(g, bmpSemilla, bmpAgua, bmpResiduo);
	}
};
}
