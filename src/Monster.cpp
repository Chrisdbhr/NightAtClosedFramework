#include "Monster.h"

Monster::Monster(float dl, GameManager *game)
{
	m_delay = dl;
	m_jumpscare.loadSound("sounds/jumpscare.mp3");
	m_naCamera[0].loadImage("images/nada.png");
	m_naCamera[1].loadImage("images/m_sala1.png");
	m_naCamera[2].loadImage("images/m_sala2.png");
	m_naCamera[3].loadImage("images/nada.png");
	m_naCamera[4].loadImage("images/m_sala4.png");
	m_naCamera[5].loadImage("images/m_naJanela.png");
	m_imgJumpscare.loadImage("images/jumpscare.png");
	animFrameTotal = m_imgJumpscare.getWidth() / m_imgJumpscare.getHeight(); // Ver quantos frames tem a animacao
	reset();
}

void Monster::reset()
{
	m_salaAtual = 3; // Qual sala esta
	m_eMorreu = false; // No caso mostrar a jumpscare
	m_kill = false; // Valido para desenhar, se a variavel anterior ta ativada, em algum momento o jogador perde, tempo aleatorio para ficar mais imprevissivel

	animFrameAtual = 0; //Qual frame da animação esta
	animTempo = 0.04f; //Contador de tempo decorrido da animacao

	m_wait = 100.f; // Tempo de espera entre acoes (Deve começar com 100.f para demorar para começar a agir)
	tempoParaDarGameOver = 0.75f; //Quanto tempo com o monstro na tela para dar GameOver
}

void Monster::update(GameManager *game)
{
	if (m_kill)
	{
		tempoParaDarGameOver -= ofGetLastFrameTime();
		if (tempoParaDarGameOver <= 0)
		{
			game->gameState = GAME_OVER;
		}
	}
	m_wait -= ofGetLastFrameTime();
	if (m_wait < 0)
	{
		if (m_eMorreu)
		{
			m_kill = true; // Ativando aqui, la no draw ja vai mostrar a animação e chamar game over
		}
		else
		{
			if (game->powerOff == true)
			{
				m_eMorreu = true;
			}
			else
			{
				m_acao = ofRandom(0, 2 + 1);
				switch (m_acao)
				{
				case M_MUDAR_DE_SALA:
					switch (m_salaAtual)
					{
					case 1:
						m_salaAtual = ofRandom(0, 2 + 1);
						break;
					case 2:
						m_salaAtual = ofRandom(1, 5 + 1);
						break;
					case 3:
						m_salaAtual = ofRandom(2, 5 + 1);
						break;
					case 4:
						m_salaAtual = ofRandom(2, 6 + 1); // 5 será o corredor
						if (m_salaAtual == 6)
						{
							m_salaAtual = 0;
						}
						break;
					case 5:
						m_salaAtual = ofRandom(2, 4 + 1);
						break;
					}
					std::cout << "sala atual: " << m_salaAtual << std::endl;
					fazerBarulho();

					break;

				case M_DESLIGAR_LUZ:
					if (m_salaAtual != 0)
					{
						game->luzADesligar = ofRandom(0, 4 + 1);
					}
					break;
				case M_DESATIVAR_CAMERA:
					game->cameraADesativar = ofRandom(1, 4 + 1);
					break;
				}
				if (m_salaAtual == 5)
				{
					game->luzADesligar = 0;
				}
			}


		}
		m_wait = ofRandom(2, 10 + m_delay - game->m_night); // o segundo parametro deve aumentar para 10 mais ou menos
	}
}

void Monster::draw()
{
	if (m_kill)
	{
		if (m_jumpscare.isPlaying() == false)
			m_jumpscare.play();

		m_imgJumpscare.drawSubsection(355, 0, m_imgJumpscare.getHeight(), m_imgJumpscare.getHeight(), animFrameAtual * m_imgJumpscare.getHeight(), 0);
		if (animTempo < 0)
		{
			animTempo = 0.03f;
			animFrameAtual == 1 ? animFrameAtual = 2 : animFrameAtual = 1; // If de uma linha
			// animFrameAtual = (animFrameAtual+1) % animFrameTotal; // Contador circular = resto / nMax (só se tivesse mais frames)
		}
		animTempo -= ofGetLastFrameTime();
	}
}

void Monster::fazerBarulho()
{
	std::string arquivo;
	arquivo.erase();
	arquivo.append("sounds/noises/");
	int som = ofRandom(0, 22 + 1);
	arquivo.append(ofToString(som));
	arquivo.append("noise.mp3");
	m_noise.loadSound(arquivo);
	m_noise.setVolume(0.6f);

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