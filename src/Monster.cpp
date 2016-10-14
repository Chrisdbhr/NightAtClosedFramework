#include "Monster.h"

Monster::Monster(float dl, GameManager *gm)
{
	game = gm; // Agora ele consegue alterar os valores do GameManager, que carrega "variaveis globais"
	m_delay = dl;
	m_jumpscare.loadSound("sounds/jumpscare.mp3");
	m_imgJumpscare.loadImage("images/jumpscare.png");
	m_naCamera[0].loadImage("images/nada.png");
	m_naCamera[1].loadImage("images/m_sala1.png");
	m_naCamera[2].loadImage("images/m_sala2.png");
	m_naCamera[3].loadImage("images/nada.png");
	m_naCamera[4].loadImage("images/m_sala4.png");
	m_naCamera[5].loadImage("images/m_naJanela.png");
}

void Monster::update()
{
	m_wait -= ofGetLastFrameTime();
	if (m_wait < 0)
	{
		if (m_eMorreu)
		{
			m_kill = true; // Ativando aqui, la no draw ja vai mostrar a animação e chamar game over
		}
		else
		{
			m_acao = ofRandom(2);
			switch (m_acao)
			{
			case M_MUDAR_DE_SALA:
				switch (m_salaAtual)
				{
				case 1:
					m_salaAtual = ofRandom(0, 2);
					break;
				case 2:
					m_salaAtual = ofRandom(1, 3);
					break;
				case 3:
					m_salaAtual = ofRandom(2, 4);
					break;
				case 4:
					m_salaAtual = ofRandom(3, 6); // 5 será o corredor
					if (m_salaAtual == 6)
					{
						m_salaAtual = 0;
					}

					break;
				default:
					m_salaAtual = ofRandom(2, 3);
					break;

				}
				std::cout << "sala atual: " << m_salaAtual << std::endl;
				fazerBarulho();

				break;

			case M_DESLIGAR_LUZ:
				if (m_salaAtual != 0)
				{
					game->luzADesligar = m_salaAtual;
				}
				break;
			case M_DESATIVAR_CAMERA:
				game->cameraADesativar = ofRandom(1, 4);
				if (m_salaAtual != 0)
				{
					game->luzADesligar = m_salaAtual;
				}
				game->luzADesligar = ofRandom(1, 4);
				break;
			}

		}
		m_wait = ofRandom(4, 5 + m_delay - game->m_night);
	}

}
void Monster::draw()
{
	if (m_kill)
	{
		std::exit(0);
	}
}

void Monster::fazerBarulho()
{
	std::string arquivo;
	arquivo.erase();
	arquivo.append("sounds/noises/");
	int som = ofRandom(1, 22);
	arquivo.append(ofToString(som));
	arquivo.append("noise.mp3");
	m_noise.loadSound(arquivo);
	m_noise.setVolume(0.8f);

	switch (m_salaAtual)
	{
	case 1:
		m_noise.setPan(-1);
		break;
	case 2:
		m_noise.setPan(-0.9f);
		break;
	case 3:
		m_noise.setPan(0.9f);
		break;
	case 4:
		m_noise.setPan(1);
		break;
	default:
		m_noise.setPan(0);
		break;
	}
	m_noise.play();
}