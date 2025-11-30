#include "GameOver.h"

void GameOver::generateRanking(const int& estrellas, const int& diff)
{
	
	try {
		string s = std::to_string(estrellas);
		ofstream Ranking;
		
		if (diff == 1) {
			Ranking.open("RankingNormal.txt", ios::app);
		
		}
		if (diff == 2) {	
			Ranking.open("RankingDificil.txt", ios::app);
			
		}
		Ranking << s << std::endl;
		
		
		Ranking.close();
		
	}
	catch (exception& ex)
	{
		cout << "Excepción al procesar el archivo: " << "Ranking.txt" << endl;
		cout << ex.what() << endl;
	}
}

void GameOver::showRanking(const int& diff) 
{

	try
	{
		ifstream Ranking;
		if (diff == 1) {
			Text* gameOver = new Text();
			gameOver->SetPosition(Vector3D(-10.0f, 25.0f, 8.0f));
			//gameOver->SetColor(Color(0, 0, 0));
			gameOver->SetText(string("GAME OVER ------  Normal "));
			this->AddGameObject(gameOver);
			Ranking.open("RankingNormal.txt");
		}
		if (diff == 2) {
			Text* gameOver = new Text();
			gameOver->SetPosition(Vector3D(-10.0f, 25.0f, 8.0f));
			//gameOver->SetColor(Color(0, 0, 0));
			gameOver->SetText(string("GAME OVER ------  Hard "));
			this->AddGameObject(gameOver);
			Ranking.open("RankingDificil.txt");
		}
		
		//int arr[MAX], arrJug[MAX];
		//int* arr;
		//int* arrJug;
		vector<int> arr;
		vector<int> arrJug;
		int n, i, j;
		int temp, temp2;
		if (Ranking.is_open())
		{
			string line;
			int cont = 0;
			int k = 1;
			
			while (getline(Ranking, line)) {

				int s = std::stoi(line);
				arr.push_back(s);
				arrJug.push_back(k);
				k++;
				cont++;

			}

			for (i = 0; i < cont; i++) {
				for (j = i; j < cont; j++) {
					if (arr[i] < arr[j]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;		//Array ordenado

						temp2 = arrJug[i];
						arrJug[i] = arrJug[j];
						arrJug[j] = temp2;
					}
				}
			}
			n = 0.0f;
			for (i = 0; i < cont; i++) {
				int num = arr[i];
				int jugador = arrJug[i];
				string s = std::to_string(num);
				string ju = std::to_string(jugador);

				Text* jug = new Text();
				jug->SetText(string("Jugador"));
				jug->SetPosition(Vector3D(-10.0f, 20.0f - n, 8.0f));
				//jug->SetColor(Color(0, 0, 0));
				this->AddGameObject(jug);

				Text* jugNum = new Text();
				jugNum->SetText(ju);
				jugNum->SetPosition(Vector3D(-1.0f, 20.0f - n, 8.0f));
				//jugNum->SetColor(Color(0, 0, 0));
				this->AddGameObject(jugNum);

				Text* t = new Text();
				t->SetText(s);
				t->SetPosition(Vector3D(15.0f, 20.0f - n, 8.0f));
				//t->SetColor(Color(0, 0, 0));
				this->AddGameObject(t);
				n += 3;
			}
		}
		Ranking.close();
	}
	catch (exception& ex)
	{
		cout << "Excepción al procesar el archivo: " << "Ranking.txt" << endl;
		cout << ex.what() << endl;
	}
}

