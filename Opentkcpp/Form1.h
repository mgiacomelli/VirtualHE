/*
 * Copyright (C) 2016 Michael Giacomelli
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  
 */

#pragma once

namespace Opentkcpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace OpenTK;
	using namespace OpenTK::Graphics;
	using namespace OpenTK::Graphics::OpenGL;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: OpenTK::GLControl^  glControl1;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton5;

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
			this->glControl1 = (gcnew OpenTK::GLControl());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// glControl1
			// 
			this->glControl1->BackColor = System::Drawing::Color::Black;
			this->glControl1->Location = System::Drawing::Point(37, 24);
			this->glControl1->Name = L"glControl1";
			this->glControl1->Size = System::Drawing::Size(1024, 1024);
			this->glControl1->TabIndex = 0;
			this->glControl1->VSync = true;
			this->glControl1->Load += gcnew System::EventHandler(this, &Form1::glControl1_Load);
			this->glControl1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::glControl1_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Location = System::Drawing::Point(1080, 290);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(154, 204);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Color Remapping Method";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(18, 27);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(51, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"None";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(18, 64);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(52, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->Text = L"Beers";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(18, 104);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(44, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->Text = L"Tao";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(18, 144);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(60, 17);
			this->radioButton5->TabIndex = 0;
			this->radioButton5->Text = L"Gareau";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 1080);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->glControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		int shaderProgram;
		bool hecolor;
	private: System::Void glControl1_Load(System::Object^  sender, System::EventArgs^  e) {
				 hecolor = false;

				 /*load a buffer of raw sesnsor data generated by a Thorlabs LSM*/
				 array<unsigned short, 3> ^ array2D = gcnew array<unsigned short, 3>(1024, 1024, 2);
				 FileStream^ fs = gcnew FileStream("..\\Raw_2.bin", FileMode::Open);
				 BinaryReader^ reader = gcnew BinaryReader(fs);

				 {
					 /*data format is 2^20 Red pixels, then 2^20 green pixels, we could easily have the shader unpack the pixels, but for simplicity do it on the CPU here*/
					 for (int i = 0; i < 1024; i++)
					 {
						 for (int j = 0; j < 1024; j++)
						 {
							 array2D[i, j, 0] = (unsigned short) (reader->ReadUInt16() * 4);	//A/D is 14 bit, so shift by 2 bits
						 }
					 }
					 for (int i = 0; i < 1024; i++)
					 {
						 for (int j = 0; j < 1024; j++)
						 {
							 array2D[i, j, 1] = (unsigned short)(reader->ReadUInt16() * 4);
						 }
					 }
				 }


				 // setup simple vertex shader
				 int vertShader = GL::CreateShader(ShaderType::VertexShader);
				 GL::ShaderSource(vertShader,
					 "varying vec4 texture_coordinate;" +
					 "void main() {" +
					 "texture_coordinate = vec4(gl_MultiTexCoord0);" +
					 "gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;" +
					 "}");
				 GL::CompileShader(vertShader);
				 Console::WriteLine(GL::GetShaderInfoLog(vertShader));

				 //setup pixel shader that can do 4 possible types of processing based on value of "colorRenderingMethod"
				 int fragShader = GL::CreateShader(ShaderType::FragmentShader);
				 GL::ShaderSource(fragShader,
					 "varying vec4 texture_coordinate;" +
					 "uniform sampler2D texture;" +
					 "uniform int colorRenderingMethod;" +
					 "vec3 k;" +
					 "void main() {" +
					 "	switch(colorRenderingMethod){" +

					 //no color mapping
					 "		case 0:"+
					 "			gl_FragColor.r =  texture2D(texture, texture_coordinate.xy).r;" +
					 "			gl_FragColor.g =  texture2D(texture, texture_coordinate.xy).g;" +
					 "			gl_FragColor.b = 0;" +
					 "			break;" +

					 //Virtual Transillumination using Beer's Law and K=2.5
					 "		case 1:" +
								//eosin beer's law calculation with beta_eosin of [0.05, 1.0, 0.544], 1.0894 and 0.0821 rescale the exponential so that exp(-1) == 0
					 "			k.r= (exp(-2.5*texture2D(texture, texture_coordinate.xy).g*0.050)-0.0821)*1.0894;" +
					 "			k.g= (exp(-2.5*texture2D(texture, texture_coordinate.xy).g*1.000)-0.0821)*1.0894;" +
					 "			k.b= (exp(-2.5*texture2D(texture, texture_coordinate.xy).g*0.544)-0.0821)*1.0894;" +
								//hematoxylin beer's law calculation applied to previous output with beta_hematoxlyin = [0.86 1.0 0.30]
					 "			gl_FragColor.r = k.r*(exp(-2.5*texture2D(texture, texture_coordinate.xy).r*0.860)-0.0821)*1.0894;" +
					 "			gl_FragColor.g = k.g*(exp(-2.5*texture2D(texture, texture_coordinate.xy).r*1.000)-0.0821)*1.0894;" +
					 "			gl_FragColor.b = k.b*(exp(-2.5*texture2D(texture, texture_coordinate.xy).r*0.300)-0.0821)*1.0894;" +
					 "			break;" +
					 //Tao 
					 "		case 2:"+
					 "			float scale = 5.076/4*.7;" +
					 "			gl_FragColor.r = 0.9 - texture2D(texture, texture_coordinate.xy).r*1.0*scale      - 0.5* texture2D(texture, texture_coordinate.xy).g*scale;" +
					 "			gl_FragColor.g = 1.1 - sqrt(texture2D(texture, texture_coordinate.xy).r*1.33*scale + 1.25 * texture2D(texture, texture_coordinate.xy).g*scale) ;" +
					 "			gl_FragColor.b = 0.9 - texture2D(texture, texture_coordinate.xy).r*0.5*scale      -texture2D(texture, texture_coordinate.xy).g*scale;" +
					 "			break;" +
					 //Gareau
					 "		case 3:"+
					 "			gl_FragColor.r = 1.0 - texture2D(texture, texture_coordinate.xy).r*(1.0-0.3) - texture2D(texture, texture_coordinate.xy).g*(1.0-1.00);" +
					 "			gl_FragColor.g = 1.0 - texture2D(texture, texture_coordinate.xy).r*(1.0-0.2) - texture2D(texture, texture_coordinate.xy).g*(1.0-0.55);" +
					 "			gl_FragColor.b = 1.0 - texture2D(texture, texture_coordinate.xy).r*(1.0-1.0) - texture2D(texture, texture_coordinate.xy).g*(1.0-0.88);" +
					 "			break;" +
					 "	}"+
					 "}");
				 GL::CompileShader(fragShader);
				 Debug::WriteLine(GL::GetShaderInfoLog(fragShader));

				 shaderProgram = GL::CreateProgram();
				 GL::AttachShader(shaderProgram, vertShader);
				 GL::AttachShader(shaderProgram, fragShader);
				 GL::LinkProgram(shaderProgram);
				 GL::ValidateProgram(shaderProgram);
				 //Console.WriteLine(GL::GetProgramInfoLog(shaderProgram));
				 GL::UseProgram(shaderProgram);
				 //Console.WriteLine(GL::GetError());

				 // 
				 GL::Enable(EnableCap::Texture2D);
				 int tex = GL::GenTexture();
				 GL::ActiveTexture(TextureUnit::Texture0);
				 GL::BindTexture(TextureTarget::Texture2D, tex);

				 {

					 /*bind the raw scanner data to an OpenGL texture*/
					 pin_ptr<unsigned short> p = &array2D[0,0,0];
					 /*tell the shader that the data in 1024x1024 pixels at 16 bits per pixel*/
					 GL::TexImage2D(TextureTarget::Texture2D, 0, PixelInternalFormat::Rg16, 1024, 1024, 0, OpenTK::Graphics::OpenGL::PixelFormat::Rg, PixelType::UnsignedShort,  System::IntPtr(p));


					 Console::WriteLine(GL::GetError());
					 GL::Uniform1(GL::GetUniformLocation(shaderProgram, "texture"), 0);
					 GL::Uniform1(GL::GetUniformLocation(shaderProgram, "colorRenderingMethod"), 0);

					 GL::TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, (int)TextureMinFilter::Linear);
					 GL::TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, (int)TextureMagFilter::Linear);

					 Console::WriteLine(GL::GetError());
				 }


				 Console::WriteLine(GL::GetError());


			 }
	private: System::Void glControl1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 GL::Clear(ClearBufferMask::ColorBufferBit | ClearBufferMask::DepthBufferBit);

				/*create a square on which to draw the texture*/
				 GL::Begin(PrimitiveType::Quads);				 
				 
				 GL::TexCoord2(0.0f, 0.0f);
				 GL::Vertex2(-1.0f, 1.0f);
				 
				 GL::TexCoord2(0.0f, 1.0f);
				 GL::Vertex2(-1.0f, -1.0f);
				 
				 GL::TexCoord2(1.0f, 1.0f);
				 GL::Vertex2(1.0f, -1.0f);
				 
				 GL::TexCoord2(1.0f, 0.0f);
				 GL::Vertex2(1.0f, 1.0f);
				 
				 GL::End();

				 /*update the texture on the screen*/
				 glControl1->SwapBuffers();

			 }

	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

				 //ignore unchecked events
				 RadioButton ^rb = (RadioButton ^) sender;
				 if(rb->Checked == false)
					 return;

				 /*figure out which radio dial was checked and then update the shader*/
				 int methodNumber=-1;
				 for (int i=groupBox1->Controls->Count-1; i>=0; i--)
				 {

					 RadioButton ^ radio = (RadioButton ^)  groupBox1->Controls[i];
					 if(radio->Checked == true)
						 methodNumber=i;

				 }
				 Debug::WriteLine("Checked:  {0}", methodNumber);

				 //update the shader with the new rendering method
				 GL::Uniform1(GL::GetUniformLocation(shaderProgram, "colorRenderingMethod"), methodNumber);
				 
				 //tell the GUI to redraw
				 glControl1->Update();
				 Refresh();
			 }
	};
}

