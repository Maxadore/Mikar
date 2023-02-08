#include "main.hpp"

using namespace std;
using namespace sf;

// Variables Globales

RenderWindow window;

Input input;

// Préparation pour l'affichage du héros

Texture heroTexture;

Sprite heroSprite;

// Hitbox du héros

FloatRect heroHitbox;

// Différentes directions / actions du héros

enum Directions { DOWN, RIGHT, UP, LEFT, DOWNWARD_ATTACK, RIGHTWARD_ATTACK, UPWARD_ATTACK, LEFTWARD_ATTACK };

// Animation du héros (la ligne à jouer)

// x = lignes et y = colonnes

Vector2i heroAnimation(0, DOWN);

// Horloge de l'animation du héros

Clock heroAnimationClock;

// Le héros est-il à l'arrêt ?

bool heroIsIdle = true;

// Gestion de l'attaque à l'épée du héros

bool needToResetHeroAnimation = false;

// Cube pour tester une première collision

RectangleShape cube(Vector2f(SPRITE_SIZE, SPRITE_SIZE));

FloatRect cubeHitbox;

// Fonction main, point de départ du programme
int main()
{
    // Création de la fenêtre
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Mikar", Style::Default);
    window.setVerticalSyncEnabled(true);

    // Chargement du visuel du héros
    if (!heroTexture.loadFromFile("resources/hero_sheet.png"))
    {
        cout << "Hero Texture Loading Error" << endl;
    }
    
    // Application de la texture au héros
    heroSprite.setTexture(heroTexture);
    // Découpage pour afficher 1 case de 32x32 pixels
    heroSprite.setTextureRect(IntRect(heroAnimation.x * SPRITE_SIZE, heroAnimation.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

    // Cube pour la collision
    cube.setFillColor(Color(250, 0, 0, 100));
    cube.setPosition(350, 250);

    // Boucle du jeu
    while (window.isOpen())
    {
        Event event;
        
        // Boucle sur les événements
        while (window.pollEvent(event))
        {
            // Gestion des entrées (clavier / souris)
            input.inputsHandler(event, window);
        }
        
        // Gestion des entrées
        checkButtons();
        
        // Animation du joueur
        playerAnimation();

        // Couleur de la fenêtre en noir
        window.clear(Color::Black);

        // Dessin des éléments
        window.draw(heroSprite);
        window.draw(cube);

        // Dessin à l'écran de tous les éléments
        window.display();

        checkCollision();
    }

    // Fin du programme
    return 0;
}

void checkButtons()
{
    // On vérifie si le héros n'est pas entrain d'attaquer
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
            needToResetHeroAnimation = true; // Après l'attaque du héros, on retourne sur l'animation de marche
            heroAnimation.x = 0; // On retourne à la colonne 0 pour jouer l'animation depuis le début
            heroAnimation.y += 4; // On descend de 4 lignes sur notre feuille de héros pour passer de la ligne "marcher" à la ligne "attaquer" sur la texture
        }
    }

    if (input.getButton().quit)
    {
        window.close();
    }
}

void playerAnimation()
{
    // Modification du héros à l'écran
    heroSprite.setTextureRect(IntRect(heroAnimation.x * SPRITE_SIZE, heroAnimation.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    
    // On anime en boucle le héros
    // On vérifie s'il s'est écoulé 0.1 seconde
    if (heroAnimationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        // On vérifie si on est à la fin de la texture (en largeur)
        if (heroAnimation.x * SPRITE_SIZE >= heroTexture.getSize().x - SPRITE_SIZE)
        {
            heroAnimation.x = 0;
            
            // On vérifie si l'animation d'attaque du héros tourne
            if (needToResetHeroAnimation)
            {
                // On arrête l'animation d'attaque du héros et on retourne sur l'animation de marche
                needToResetHeroAnimation = false;
                heroAnimation.y -= 4;
            }
        }
        // On vérifie si on n'est pas encore à la fin de la texture (en largeur)
        else
        {
            // On vérifie si le héros n'est pas à l'arrêt
            if (!heroIsIdle || needToResetHeroAnimation)
            {
                heroAnimation.x++;
            }
        }
        
        heroAnimationClock.restart();
    }
}

// Teste la collision entre héros et le cube
void checkCollision()
{
    // Hitbox du héros
    heroHitbox = heroSprite.getGlobalBounds();
    
    // Hitbox du cube
    cubeHitbox = cube.getGlobalBounds();

    // On vérifie si le héros entre en collision avec le cube
    if (heroHitbox.intersects(cubeHitbox))
    {
        // On affiche un simple message en console indiquant qu'il y a bien une collision
        cout << "Collision !" << endl;
    }
}