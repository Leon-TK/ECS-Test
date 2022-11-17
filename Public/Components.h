
struct Component
{

};

struct Position2dComponent: public Component
{
	int X;
	int Y;
};

struct PlayerOffset2dComponent: public Component
{
	int xOffset;
	int yOffset;
};

struct RenderComponent: public Component
{
	Texture2D texture;
};

struct Axis2dComponent: public Component
{
	int UpAxis;
	int RightAxis;
};

struct PlayerAxisComponent
{
	int UpAxis;
	int RightAxis;
};
