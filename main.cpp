#include "main.hpp"

using namespace std;
using namespace sf;

// Variables Globales

RenderWindow window;

Input input;

// Pr�paration pour l'affichage du h�ros

Texture heroTexture;

Sprite heroSprite;

// Hitbox du h�ros

FloatRect heroHitbox;

// Diff�rentes directions / actions du h�ros

enum Directions { DOWN, RIGHT, UP, LEFT, DOWNWARD_ATTACK, RIGHTWARD_ATTACK, UPWARD_ATTACK, LEFTWARD_ATTACK };

// Animation du h�ros (la ligne � jouer)

// x = lignes et y = colonnes

Vector2i heroAnimation(0, DOWN);

// Horloge de l'animation du h�ros

Clock heroAnimationClock;

// Le h�ros est-il � l'arr�t ?

bool heroIsIdle = true;

// Gestion de l'attaque � l'�p�e du h�ros

bool needToResetHeroAnimation = false;

// Cube pour tester une premi�re collision

RectangleShape cube(Vector2f(SPRITE_SIZE, SPRITE_SIZE));

FloatRect cubeHitbox;

// Fonction main, point de d�part du programme
int main()
{
    // Cr�ation de la fen�tre
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Mikar", Style::Default);
    window.setVerticalSyncEnabled(true);

    // Chargement du visuel du h�ros
    if (!heroTexture.loadFromFile("resources/hero_sheet.png"))
    {
        cout << "Hero Texture Loading Error" << endl;
    }
    
    // Application de la texture au h�ros
    heroSprite.setTexture(heroTexture);
    // D�coupage pour afficher 1 case de 32x32 pixels
    heroSprite.setTextureRect(IntRect(heroAnimation.x * SPRITE_SIZE, heroAnimation.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

    // Cube pour la collision
    cube.setFillColor(Color(250, 0, 0, 100));
    cube.setPosition(350, 250);

    // Boucle du jeu
    while (window.isOpen())
    {
        Event event;
        
        // Boucle sur les �v�nements
        while (window.pollEvent(event))
        {
            // Gestion des entr�es (clavier / souris)
            input.inputsHandler(event, window);
        }
        
        // Gestion des entr�es
        checkButtons();
        
        // Animation du joueur
        playerAnimation();

        // Couleur de la fen�tre en noir
        window.clear(Color::Black);

        // Dessin des �l�ments
        window.draw(heroSprite);
        window.draw(cube);

        // Dessin � l'�cran de tous les �l�ments
        window.display();

        checkCollision();
    }

    // Fin du programme
    return 0;
}

void checkButtons()
{
    // On v�rifie si le h�ros n'est pas entrain d'attaquer
    if (!needToResetHeroAnimation)
    {
        if (input.getButton().left)
        {
            heroAnimation.y = LEFT;
            heroSprite.move(-HERO_SPEED, 0);
            heroIsIdle = false;
        }
        else if (input.getButton().right)
        {
            heroAnimation.y = RIGHT;
            heroSprite.move(HERO_SPEED, 0);
            heroIsIdle = false;
        }
        else if (input.getButton().up)
        {
            heroAnimation.y = UP;
            heroSprite.move(0, -HERO_SPEED);
            heroIsIdle = false;
        }
        else if (input.getButton().down)
        {
            heroAnimation.y = DOWN;
            heroSprite.move(0, HERO_SPEED);
            heroIsIdle = false;
        }
        else
        {
            heroIsIdle = true;
        }
        
        if (input.getButton().attack)
        {
            needToResetHeroAnimation = true; // Apr�s l'attaque du h�ros, on retourne sur l'animation de marche
            heroAnimation.x = 0; // On retourne � la colonne 0 pour jouer l'animation depuis le d�but
            heroAnimation.y += 4; // On descend de 4 lignes sur notre feuille de h�ros pour passer de la ligne "marcher" � la ligne "attaquer" sur la texture
        }
    }

    if (input.getButton().quit)
    {
        window.close();
    }
}

void playerAnimation()
{
    // Modification du h�ros � l'�cran
    heroSprite.setTextureRect(IntRect(heroAnimation.x * SPRITE_SIZE, heroAnimation.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    
    // On anime en boucle le h�ros
    // On v�rifie s'il s'est �coul� 0.1 seconde
    if (heroAnimationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        // On v�rifie si on est � la fin de la texture (en largeur)
        if (heroAnimation.x * SPRITE_SIZE >= heroTexture.getSize().x - SPRITE_SIZE)
        {
            heroAnimation.x = 0;
            
            // On v�rifie si l'animation d'attaque du h�ros tourne
            if (needToResetHeroAnimation)
            {
                // On arr�te l'animation d'attaque du h�ros et on retourne sur l'animation de marche
                needToResetHeroAnimation = false;
                heroAnimation.y -= 4;
            }
        }
        // On v�rifie si on n'est pas encore � la fin de la texture (en largeur)
        else
        {
            // On v�rifie si le h�ros n'est pas � l'arr�t
            if (!heroIsIdle || needToResetHeroAnimation)
            {
                heroAnimation.x++;
            }
        }
        
        heroAnimationClock.restart();
    }
}

// Teste la collision entre h�ros et le cube
void checkCollision()
{
    // Hitbox du h�ros
    heroHitbox = heroSprite.getGlobalBounds();
    
    // Hitbox du cube
    cubeHitbox = cube.getGlobalBounds();

    // On v�rifie si le h�ros entre en collision avec le cube
    if (heroHitbox.intersects(cubeHitbox))
    {
        // On affiche un simple message en console indiquant qu'il y a bien une collision
        cout << "Collision !" << endl;
    }
}