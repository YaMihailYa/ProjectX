#include "Render.h"
#include "Room_regular.h"
#include "Player.h"
#include "Menu.h"
#include "Texture_loader.h"
/*
|100|50|100|

*/
int main()
{
	/*Render *render = new Render;
	render->Rendering();
	delete render;
*/
	/*Texture_loader loader;
	loader.Add_texture("img/background.png");*/

	Render *render = new Render;
	render->Rendering();
	delete render;
	/*Player p;
	p.Set_c_room(0);

	Room_regular r1(0, sf::IntRect(0, 0, 100, 0), true);
	Room_regular r2(1, sf::IntRect(100, 0, 50, 0), true);
	Room_regular r3(2, sf::IntRect(150, 0, 100, 0), true);
	r1.Set_right_room(&r2);
	r2.Set_left_room(&r1);
	r2.Set_right_room(&r3);
	r3.Set_left_room(&r2);

	std::vector<Room_regular*> rooms;
	rooms.push_back(&r1);
	rooms.push_back(&r2);
	rooms.push_back(&r3);

	sf::IntRect old_rect, new_rect;
	old_rect.height = 0;
	old_rect.top = 0;
	new_rect.height = 0;
	new_rect.top = 0;
	sf::IntRect new_coords;
	int dir;
	while(true)
	{
		scanf_s("%d %d %d %d %d", &old_rect.left, &old_rect.width, &new_rect.left, &new_rect.width, &dir);
		new_coords = rooms[Player::Get()->Get_c_room()]->move_player(old_rect, new_rect, static_cast<Direction_t>(dir));
		printf("new: %d %d %u\n", new_coords.left, new_coords.width, Player::Get()->Get_c_room());
	}*/


	return 0;
}
