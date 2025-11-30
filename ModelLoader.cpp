#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath, const string& matPath)
{
	LoadMat(matPath);
	try
	{
		ifstream objFile(filePath);
	
		if (objFile.is_open())
		{
			string line;
			int i = -1;
			while (getline(objFile, line))
			{
				if (line[0] == 'v' && line[1] == 'n')
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normal.push_back(normal);
				}
				else if (line[0] == 'v')
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexes.push_back(vertex);
				}
				else if (line[0] == 'f')
				{
					Triangle triangle = this->parseObjTriangle(line,colors[i]);
					this->model.AddTriangle(this->center(triangle));
					//this->model.AddTriangle(triangle);
				}
				else if (line[0] == 'u' && line[1] == 's' && line[2] == 'e' && line[3] == 'm' && line[4] == 't' && line[5] == 'l') 
				{
					i++;
				}
				if (line[0] == 'v' && line[1] == 't')
				{
					Vector3D texture = this->parseObjLineToVector2D(line);
					this->textures.push_back(texture);
				}
			}
			objFile.close();
		}
		else
		{
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex)
	{
		cout << "Excepción al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

void ModelLoader::LoadMat(const string& matPath)
{
	try
	{
		ifstream objFile1(matPath);
		if (objFile1.is_open())
		{
			string line0;
			int count0 = 0;
			while (getline(objFile1, line0))
			{
				 if (line0[0] == 'K' && line0[1] == 'd')
				{
					Color color = this->parseObjLineToColor(line0);
					this->colors.push_back(color);
				}
			}
			objFile1.close();
		}
		else
		{
		cout << "No se ha podido abrir el archivo: " << matPath << endl;
		}
	}
	catch (exception& ex)
	{
		cout << "Excepción al procesar el archivo: " << matPath << endl;
		cout << ex.what() << endl;
	}
}


Vector3D ModelLoader::parseObjLineToVector3D(const string& line)
{
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->GetScale();
}

Vector3D ModelLoader::parseObjLineToVector2D(const string& line)
{
	string typeOfPoint;
	float xCoordinate, yCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, 0);
	return vectorPoint;
}

Color ModelLoader::parseObjLineToColor(const string& line)
{
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Color vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint;
}


Triangle ModelLoader::parseObjTriangle(const string& line, Color color)
{
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;
	int idxTexture0, idxTexture1, idxTexture2;

	istringstream stringStream(line);
	stringStream >> c;

	//Para Modelos Sin Coordenadas de Textura en las Caras
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertexes[idxVertex0 - 1.0f];
	Vector3D vertex1 = this->vertexes[idxVertex1 - 1.0f];
	Vector3D vertex2 = this->vertexes[idxVertex2 - 1.0f];
	Vector3D normal0 = this->normal[idxNormal0 - 1.0f];
	Vector3D normal1 = this->normal[idxNormal1 - 1.0f];
	Vector3D normal2 = this->normal[idxNormal2 - 1.0f];

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal0, normal1, normal2, color, color, color);

	return parsedTriangle;
}

void ModelLoader::calcBoundaries(Vector3D vectorPoint)
{
	this->maxX = fmax(this->maxX, vectorPoint.GetX());
	this->maxY = fmax(this->maxY, vectorPoint.GetY());
	this->maxZ = fmax(this->maxZ, vectorPoint.GetZ());
	this->minX = fmin(this->minX, vectorPoint.GetX());
	this->minY = fmin(this->minY, vectorPoint.GetY());
	this->minZ = fmin(this->minZ, vectorPoint.GetZ());
}

Triangle ModelLoader::center(Triangle triangle)
{
	Vector3D modelCenter(this->minX + this->GetWidth() / 2.0f,
		this->minY + this->GetHeight() / 2.0f,
		this->minZ + this->GetLength() / 2.0f);
	Triangle centeredTriangle(
		triangle.GetVertex0() - modelCenter,
		triangle.GetVertex1() - modelCenter,
		triangle.GetVertex2() - modelCenter,
		triangle.GetNormals0(),
		triangle.GetNormals1(),
		triangle.GetNormals2(),
		triangle.GetColor0(),
		triangle.GetColor1(),
		triangle.GetColor2());

		/*triangle.GetTextureCoordinates0(),
		triangle.GetTextureCoordinates1(),
		triangle.GetTextureCoordinates2());*/

	return centeredTriangle;
}
	
void ModelLoader::Clear()
{
	this->vertexes.clear();
	this->normal.clear();
	this->model.Clear();
	this->colors.clear();
	//this->textures.clear();
	this->maxX = 0;
	this->maxY = 0;
	this->maxZ = 0;
	this->minX = 0;
	this->minY = 0;
	this->minZ = 0;
}