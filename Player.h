
class PLAYER
{
private:
	
	#define VFrame 7
	#define DFrame 7
	#define AFrame 3
	
	int SizeX;
	int SizeY;
	
	float x;
	float y;
	
	FloatRect rect;
	Texture TPlayer;

	float time;
	
	float NumberFrame;	
	float NumberDownFrame;
	float NumberAttackFrame;
	
	float AOG;
										
	char OldVector;
	
	bool onGround;
	
	string TypeAttack;
	
public:
	
	PLAYER();
	
	~PLAYER();

public:
	
	float Speed;
	
	int FloorLevel;
	
	Sprite sprite;
	
private:
	
	void GravityAndMotion();
	
public:
	
	void Attack(string Type);
	
	void Update(float time);
	
	void Control();
};
