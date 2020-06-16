


//dino
#define GRAVITY -1000.0f
#define DINO_JUMPING_TOLERANCE 3
#define DINO_SPEED_Y_MIN -500.0f
#define DINO_SPEED_Y_MAX 400.0f
#define DINO_SPEED_X_INITIAL 300.0f
#define DINO_SPEED_X_INCREASING_RATE 5
#define DINO_X 60.0f

//cactus
#define CACTUS_NUMBER 5
#define CACTUS_INITIAL_X 735
#define CACTUS_SPEED_RATIO 1

//cloud
#define CLOUD_SPEED_RATIO 0.4f
#define CLOUD_Y_MIN 600
#define CLOUD_Y_MAX 800
#define CLOUD_SPACING_MIN 100
#define CLOUD_SPACING_MAX 500
#define CLOUD_NUMBER 10

//zOrder
#define CACTUS_ZORDER 3
#define DINO_ZORDER 4
#define GROUD_ZORDER 5
#define CLOUD_ZORDER 6
#define SCORE_ZORDER 7
#define ROAD_ZORDER 4

//groud / road
#define GROUND_HEIGHT 350
#define ROAD_SPEED_RATIO 1
#define ROAD_2_PROBABILITY 30

//title
#define TITLE_INITIAL_Y 150
#define TITLE_HIDDEN_Y 100
#define TITLE_ANIMATION_TIME 0.2f

//storage
#define STORE_HIGH_SCORE "HIGH_SCORE"

//score
#define SCORE_TEXT "%d - SCORE"
#define HIGHSCORE_TEXT "HIGH - %d"
#define SCORE_RATE 6
#define FAKE_HIGHSCORE 100

// SOUND
#define SOUND_JUMP "jum.wav"
#define SOUND_OVER "over.wav"
#define SOUND_NEW_HIGH "newhigh.wav"
#define SOUND_HIT_GROUND "hitground.wav"