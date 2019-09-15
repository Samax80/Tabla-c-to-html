// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

//HOLA MAURICIO EL PROGRAMA ESTA EN C++ ADAPTADO PARA GUARDAR ARCHIVO COMO HTML>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdarg>
#include <memory>

//funcionen c++ que es similar a  string.format in c#
std::string format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
#ifndef _MSC_VER
	size_t size = std::snprintf(nullptr, 0, format, args) + 1; // Extra space for '\0'
	std::unique_ptr<char[]> buf(new char[size]);
	std::vsnprintf(buf.get(), size, format, args);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
#else
	int size = _vscprintf(format, args);
	std::string result(++size, 0);
	vsnprintf_s((char*)result.data(), size, _TRUNCATE, format, args);
	return result;
#endif
	va_end(args);
}


int main()
{

	std::string varHtml;
	auto encabezado = "<html>";
	auto encabezadoC = "</html>";
	auto body = "<body>";
	auto bodyC = "</body>";
	auto tabla = "<table border='1'>";
	auto tablaC = "</table>";
	auto saltoPagina = "\r\n";
	auto horizontal = 10;//pendiente por ser actualizado por el usuario.
	auto vertical = 10;//pendiente por ser actualizado por el usuario.
	std::string color = "";
	std::string font = "";
	//std::string intro = "Hola, seleccione la cantidad de celdas  horizontales='horizontal' y verticales='vertical' ";
	

	std::string a = "test";
	std::string b = "text.txt";
	std::string c = "text1.txt";

	std::stringstream s;
	s << a << " " << b << " > " << c;
	// assign to std::string
	std::string str = s.str();
	std::cout << str << "\n";

	
	varHtml = encabezado + std::string(saltoPagina);
	varHtml += body + std::string(saltoPagina);
	varHtml += tabla + std::string(saltoPagina);
	varHtml += "<tr>" + std::string(saltoPagina);
	

	//Prints X
	varHtml += "<td>" + std::string("X") + "</td>" + std::string(saltoPagina);//prints "x" at the origin

	//Horizontal        
	for (int h = 1;h <= horizontal;++h)
	{


		varHtml += "<td>" + std::to_string(h) + "</td>" + std::string(saltoPagina); //Prints nummber from 1 to i  horizontal


	}

	varHtml += "</tr>" + std::string(saltoPagina);
	int x = 1;
	int g = 1;

	//Vertical
	for (int v = 1;v <= vertical;++v)
	{


		varHtml += "<tr>" + std::string(saltoPagina);

		varHtml += "<td>" + std::to_string(v) + "</td>" + std::string(saltoPagina);

		//Horizontal        
		for (int number = 1;number <= horizontal;++number)
		{

			int value = x * g;

			if (value % 2 == 0)//numeros pares
			{
				color = "bgcolor='#000000'";//fondo negro
				font = "font color='white'";

				//<font color="red">
			}
			else//impares
			{
				
				color = "bgcolor='#FF66CC'";// fondo rosa 
				font = "font color=black";
			}

		
			//automatizar color
			auto celda = format(" <td %s> <%s> ", color.c_str(), font.c_str());
			varHtml += celda;
			varHtml += std::to_string(value) + "</font>"  + "</td>" + std::string(saltoPagina); //Prints nummber from 1 to i  horizontal
			g = g + 1;

		}
		g = 1;
		x = x + 1;

		varHtml += "</tr>" + std::string(saltoPagina);
	}

	varHtml += tablaC + std::string(saltoPagina);
	varHtml += saltoPagina + std::string(saltoPagina);
	varHtml += bodyC + std::string(saltoPagina);
	varHtml += saltoPagina + std::string(saltoPagina);
	varHtml += encabezadoC + std::string(saltoPagina);

	std::cout << varHtml << std::endl;

	//WRITE FILE TO HTML
	std::ofstream savedFile;//Write to a file
	savedFile.open("../Tablero.html");//Open file after execution
	savedFile << varHtml << std::endl;//Write to file
	savedFile.close();//After writing to file , the program have to be closed using "outfile.close()"


	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

