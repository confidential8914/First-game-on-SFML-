
class PLAYER
{
private:
	
	#define VFrame 7
	#define DFrame 7
	#define AFrame 3
	
	Texture TPlayer;

	float time;
	
	float NumberFrame;	
	float NumberDownFrame;
	float NumberAttackFrame;
	
	float AOG;
										
	char OldVector;
	
	string TypeAttack;
	
public:
	
	PLAYER();
	
	~PLAYER();

public:
	
	Clock Clock; 
	
	short int VH; 
	
	int   health;
	float charges;
	
	float offsetX;
	float offsetY;
	
	int SizeX;
	int SizeY;
	
	float x;
	float y;
	
	bool onGround;
	
	FloatRect rect;
	
	float Speed;
	float SizeJump;
	
	Sprite sprite;
	
private:
	
	void GravityAndMotion();
	void Charges(); 
		
public:
	
	void Attack(string Type);
	
	void Update(float time, float offsetX, float offsetY);
	
	void Control();
};
