#include <stdlib.h>
#include <limits.h>
#include <sys/cdefs.h>
#include <sys/time.h>
#include <math.h>

typedef	int				ch_ret;
typedef	int				obj_ret;

/*
 * Short scalar types.
 * Diavolo reports AIX compiler has bugs with short types.
 */
#if	!defined(FALSE)
#define FALSE	 0
#endif

#if	!defined(TRUE)
#define TRUE	 1
#endif

#if	!defined(BERR)
#define BERR	 255
#endif

#if	defined(_AIX)
#if	!defined(const)
#define const
#endif
typedef int				sh_int;
typedef int				bool;
#define unix
#else
typedef short    int			sh_int;
typedef unsigned char			bool;
#endif

/*
 * Structure types.
 */
typedef struct affect_data		    AFFECT_DATA;
typedef struct area_data		    AREA_DATA;
typedef struct auction_data         AUCTION_DATA; /* auction data */
typedef struct ban_data		        BAN_DATA;
typedef struct extracted_char_data  EXTRACT_CHAR_DATA;
typedef struct char_data		    CHAR_DATA;
typedef struct hunt_hate_fear		HHF_DATA;
typedef struct fighting_data		FIGHT_DATA;
typedef struct descriptor_data		DESCRIPTOR_DATA;
typedef struct exit_data		    EXIT_DATA;
typedef struct extra_descr_data	    EXTRA_DESCR_DATA;
typedef struct help_data		    HELP_DATA;
typedef struct menu_data		    MENU_DATA;
typedef struct mob_index_data		MOB_INDEX_DATA;
typedef struct note_data		    NOTE_DATA;
typedef struct board_data		    BOARD_DATA;
typedef struct obj_data		        OBJ_DATA;
typedef struct obj_index_data		OBJ_INDEX_DATA;
typedef struct pc_data			    PC_DATA;
typedef struct map_index_data		MAP_INDEX_DATA;   /* maps */
typedef struct map_data		        MAP_DATA;   /* maps */
typedef struct room_index_data		ROOM_INDEX_DATA;
typedef struct shop_data		    SHOP_DATA;
typedef struct repairshop_data		REPAIR_DATA;
typedef struct time_info_data		TIME_INFO_DATA;
typedef struct hour_min_sec		    HOUR_MIN_SEC;
typedef struct weather_data		    WEATHER_DATA;
typedef struct planet_data		    PLANET_DATA;
typedef struct guard_data		    GUARD_DATA;
typedef struct space_data           SPACE_DATA;
typedef	struct clan_data		    CLAN_DATA;
typedef	struct senate_data		    SENATE_DATA;
typedef struct ship_data            SHIP_DATA;
typedef struct hanger_data          HANGER_DATA;
typedef struct turret_data          TURRET_DATA;
typedef struct ship_prototype_data  SHIP_PROTOTYPE;
typedef struct missile_data         MISSILE_DATA;
typedef struct tourney_data         TOURNEY_DATA;
typedef struct mob_prog_data		MPROG_DATA;
typedef struct mob_prog_act_list	MPROG_ACT_LIST;
typedef	struct editor_data		    EDITOR_DATA;
typedef struct teleport_data		TELEPORT_DATA;
typedef struct timer_data		    TIMER;
typedef struct vote_data		    VOTE_DATA;
typedef struct system_data		    SYSTEM_DATA;
typedef	struct smaug_affect		    SMAUG_AFF;
typedef struct who_data             WHO_DATA;
typedef	struct skill_type		    SKILLTYPE;
typedef	struct social_type		    SOCIALTYPE;
typedef	struct cmd_type		        CMDTYPE;
typedef	struct killed_data		    KILLED_DATA;
typedef struct wizent			    WIZENT;

/*
 * Function types.
 */
typedef	void	DO_FUN(CHAR_DATA* ch, char* argument);
typedef bool	SPEC_FUN(CHAR_DATA* ch);
typedef ch_ret	SPELL_FUN(int sn, int level, CHAR_DATA* ch, void* vo);

#define DUR_CONV	23.333333333333333333333333
#define HIDDEN_TILDE	'*'

#define BV00		(1 <<  0)
#define BV01		(1 <<  1)
#define BV02		(1 <<  2)
#define BV03		(1 <<  3)
#define BV04		(1 <<  4)
#define BV05		(1 <<  5)
#define BV06		(1 <<  6)
#define BV07		(1 <<  7)
#define BV08		(1 <<  8)
#define BV09		(1 <<  9)
#define BV10		(1 << 10)
#define BV11		(1 << 11)
#define BV12		(1 << 12)
#define BV13		(1 << 13)
#define BV14		(1 << 14)
#define BV15		(1 << 15)
#define BV16		(1 << 16)
#define BV17		(1 << 17)
#define BV18		(1 << 18)
#define BV19		(1 << 19)
#define BV20		(1 << 20)
#define BV21		(1 << 21)
#define BV22		(1 << 22)
#define BV23		(1 << 23)
#define BV24		(1 << 24)
#define BV25		(1 << 25)
#define BV26		(1 << 26)
#define BV27		(1 << 27)
#define BV28		(1 << 28)
#define BV29		(1 << 29)
#define BV30		(1 << 30)
#define BV31		(1 << 31)
/* 32 USED! DO NOT ADD MORE! SB */

/*
 * String and memory management parameters.
 */
#define MAX_KEY_HASH        2048
#define MAX_STRING_LENGTH   4096    /* buf */
#define MAX_INPUT_LENGTH    1024    /* arg */
#define MAX_INBUF_SIZE      1024

#define HASHSTR                     /* use string hashing */

#define	MAX_LAYERS		    8       /* maximum clothing layers */
#define MAX_NEST            100     /* maximum container nesting */

#define MAX_KILLTRACK		20      /* track mob vnums killed */

/*
 * Game parameters.
 * Increase the max'es if you add more of something.
 * Adjust the pulse numbers to suit yourself.
 */
#define MAX_EXP_WORTH	    500000
#define MIN_EXP_WORTH		25

#define MAX_REXITS		    20      /* Maximum exits allowed in 1 room */
#define MAX_SKILL		    276
#define MAX_LEVEL		    105
#define MAX_CLAN		    50
#define MAX_PLANET		    100
#define MAX_SHIP            1000
#define MAX_SHIP_ROOMS      25

#define PULSE_PER_SECOND    4
#define PULSE_MINUTE        (60 * PULSE_PER_SECOND)
#define PULSE_VIOLENCE		( 3 * PULSE_PER_SECOND)
#define PULSE_MOBILE		( 4 * PULSE_PER_SECOND)
#define PULSE_TICK		    (70 * PULSE_PER_SECOND)
#define PULSE_AUCTION       (10 * PULSE_PER_SECOND)
#define PULSE_SPACE         (10 * PULSE_PER_SECOND)
#define PULSE_TAXES         (60 * PULSE_MINUTE)
#define PULSE_AREA		    (15 * PULSE_MINUTE)

/*
 * Command logging types.
 */
typedef enum
{
    LOG_NORMAL, LOG_ALWAYS, LOG_NEVER, LOG_BUILD, LOG_HIGH, LOG_COMM, LOG_ALL
} log_types;

/*
 * Return types for move_char, damage, greet_trigger, etc, etc
 * Added by Thoric to get rid of bugs
 */
typedef enum
{
    rNONE, rCHAR_DIED, rVICT_DIED, rBOTH_DIED, rCHAR_QUIT, rVICT_QUIT,
    rBOTH_QUIT, rSPELL_FAILED, rOBJ_SCRAPPED, rOBJ_EATEN, rOBJ_EXPIRED,
    rOBJ_TIMER, rOBJ_SACCED, rOBJ_QUAFFED, rOBJ_USED, rOBJ_EXTRACTED,
    rOBJ_DRUNK, rCHAR_IMMUNE, rVICT_IMMUNE, rCHAR_AND_OBJ_EXTRACTED = 128,
    rERROR = 255
} ret_types;

/* Echo types for echo_to_all */
#define ECHOTAR_ALL 0
#define ECHOTAR_PC  1
#define ECHOTAR_IMM 2

/* defines for new do_who */
#define WT_MORTAL   0
#define WT_IMM      2
#define WT_AVATAR   1
#define WT_NEWBIE   3

/*
 * do_who output structure -- Narn
 */
struct who_data
{
    WHO_DATA* prev;
    WHO_DATA* next;
    char* text;
    int  type;
};

/*
 * Site ban structure.
 */
struct	ban_data
{
    BAN_DATA* next;
    BAN_DATA* prev;
    char* name;
    int		level;
    char* ban_time;
};


/*
 * Time and weather stuff.
 */
typedef enum
{
    SUN_DARK, SUN_RISE, SUN_LIGHT, SUN_SET
} sun_positions;

typedef enum
{
    SKY_CLOUDLESS, SKY_CLOUDY, SKY_RAINING, SKY_LIGHTNING
} sky_conditions;

struct	time_info_data
{
    int		hour;
    int		day;
    int		month;
    int		year;
};

struct hour_min_sec
{
    int hour;
    int min;
    int sec;
    int manual;
};

struct	weather_data
{
    int		mmhg;
    int		change;
    int		sky;
    int		sunlight;
};

/*
 * Connected state for a channel.
 */
typedef enum
{
    CON_PLAYING, CON_GET_NAME, CON_GET_OLD_PASSWORD,
    CON_CONFIRM_NEW_NAME, CON_GET_NEW_PASSWORD, CON_CONFIRM_NEW_PASSWORD,
    CON_GET_NEW_SEX, CON_DONE_MOTD,
    CON_GET_EMULATION, CON_EDITING,
    CON_GET_WANT_RIPANSI, CON_TITLE, CON_PRESS_ENTER,
    CON_WAIT_1, CON_WAIT_2, CON_WAIT_3,
    CON_ACCEPTED, CON_GET_PKILL, CON_READ_IMOTD,
    CON_GET_NEW_EMAIL, CON_GET_MSP, CON_GET_NEW_CLASS,
    CON_ROLL_STATS, CON_STATS_OK, CON_ADD_SKILLS,
    CON_READ_NMOTD, CON_PICK_CLAN
} connection_types;

/*
 * Character substates
 */
typedef enum
{
    SUB_NONE, SUB_PAUSE, SUB_PERSONAL_DESC, SUB_OBJ_SHORT, SUB_OBJ_LONG,
    SUB_OBJ_EXTRA, SUB_MOB_LONG, SUB_MOB_DESC, SUB_ROOM_DESC, SUB_ROOM_EXTRA,
    SUB_ROOM_EXIT_DESC, SUB_WRITING_NOTE, SUB_MPROG_EDIT, SUB_HELP_EDIT,
    SUB_WRITING_MAP, SUB_PERSONAL_BIO, SUB_REPEATCMD, SUB_RESTRICTED,
    SUB_SHIPDESC, SUB_CLANDESC,

    /**
     * @brief Character is editing a change description.
     */
    SUB_CHANGE_DESC,
    /* timer types ONLY below this point */
    SUB_TIMER_DO_ABORT = 128, SUB_TIMER_CANT_ABORT
} char_substates;

/*
 * Descriptor (channel) structure.
 */
struct	descriptor_data
{
    DESCRIPTOR_DATA* next;
    DESCRIPTOR_DATA* prev;
    DESCRIPTOR_DATA* snoop_by;
    CHAR_DATA* character;
    CHAR_DATA* original;
    char* host;
    char* hostip;
    int			port;
    int			descriptor;
    sh_int		connected;
    sh_int		idle;
    sh_int		lines;
    sh_int		scrlen;
    bool		fcommand;
    char		inbuf[MAX_INBUF_SIZE];
    char		incomm[MAX_INPUT_LENGTH];
    char		inlast[MAX_INPUT_LENGTH];
    int			repeat;
    char* outbuf;
    unsigned long	outsize;
    int			outtop;
    char* pagebuf;
    unsigned long	pagesize;
    int			pagetop;
    char* pagepoint;
    char		pagecmd;
    char		pagecolor;
    int			auth_inc;
    int			auth_state;
    char		abuf[256];
    int			auth_fd;
    char* user;
    int 		atimes;
    int			newstate;
    unsigned char	prevcolor;
};



/*
 * Attribute bonus structures.
 */
struct	str_app_type
{
    sh_int	tohit;
    sh_int	todam;
    sh_int	carry;
    sh_int	wield;
};

struct	int_app_type
{
    sh_int	learn;
};

struct	wis_app_type
{
    sh_int	practice;
};

struct	dex_app_type
{
    sh_int	defensive;
};

struct	con_app_type
{
    sh_int	hitp;
    sh_int	shock;
    sh_int	stun;
};

struct	cha_app_type
{
    sh_int	charm;
};

struct  lck_app_type
{
    sh_int	luck;
};

struct  frc_app_type
{
    sh_int	force;
};

/*
 * TO types for act.
 */
#define TO_ROOM		    0
#define TO_NOTVICT	    1
#define TO_VICT		    2
#define TO_CHAR		    3

/*
 * Real action "TYPES" for act.
 */
#define AT_BLACK	    0
#define AT_BLOOD	    1
#define AT_DGREEN           2
#define AT_ORANGE	    3
#define AT_DBLUE	    4
#define AT_PURPLE	    5
#define AT_CYAN	  	    6
#define AT_GREY		    7
#define AT_DGREY	    8
#define AT_RED		    9
#define AT_GREEN	   10
#define AT_YELLOW	   11
#define AT_BLUE		   12
#define AT_PINK		   13
#define AT_LBLUE	   14
#define AT_WHITE	   15
#define AT_BLINK	   16
#define AT_PLAIN	   AT_GREY
#define AT_ACTION	   AT_GREY
#define AT_SAY		   AT_LBLUE
#define AT_GOSSIP	   AT_LBLUE
#define AT_YELL	           AT_WHITE
#define AT_TELL		   AT_BLUE
#define AT_HIT		   AT_WHITE
#define AT_HITME	   AT_YELLOW
#define AT_OOC             AT_YELLOW
#define AT_IMMORT	   AT_WHITE
#define AT_AVATAR	   AT_BLUE
#define AT_HURT		   AT_RED
#define AT_FALLING	   AT_WHITE + AT_BLINK
#define AT_DANGER	   AT_RED + AT_BLINK
#define AT_MAGIC	   AT_BLUE
#define AT_CONSIDER	   AT_GREY
#define AT_REPORT	   AT_GREY
#define AT_POISON	   AT_GREEN
#define AT_SOCIAL	   AT_CYAN
#define AT_DYING	   AT_YELLOW
#define AT_DEAD		   AT_RED
#define AT_SKILL	   AT_GREEN
#define AT_CARNAGE	   AT_BLOOD
#define AT_DAMAGE	   AT_WHITE
#define AT_FLEE		   AT_YELLOW
#define AT_RMNAME	   AT_WHITE
#define AT_RMDESC	   AT_GREY
#define AT_OBJECT	   AT_GREEN
#define AT_PERSON	   AT_PINK
#define AT_LIST		   AT_BLUE
#define AT_BYE		   AT_GREEN
#define AT_GOLD		   AT_YELLOW
#define AT_GTELL	   AT_BLUE
#define AT_NOTE		   AT_GREEN
#define AT_HUNGRY	   AT_ORANGE
#define AT_THIRSTY	   AT_BLUE
#define	AT_FIRE		   AT_RED
#define AT_SOBER	   AT_WHITE
#define AT_WEAROFF	   AT_YELLOW
#define AT_EXITS	   AT_WHITE
#define AT_SCORE	   AT_LBLUE
#define AT_RESET	   AT_DGREEN
#define AT_LOG		   AT_PURPLE
#define AT_DIEMSG	   AT_WHITE
#define AT_WARTALK     AT_RED
#define AT_SHIP        AT_PINK
#define AT_CLAN        AT_PINK

#define INIT_WEAPON_CONDITION   12
#define MAX_ITEM_IMPACT		    30

/*
 * Help table types.
 */
struct	help_data
{
    HELP_DATA* next;
    HELP_DATA* prev;
    sh_int	level;
    char* keyword;
    char* text;
};



/*
 * Shop types.
 */
#define MAX_TRADE	 5

struct	shop_data
{
    SHOP_DATA* next;			/* Next shop in list		*/
    SHOP_DATA* prev;			/* Previous shop in list	*/
    int		keeper;			/* Vnum of shop keeper mob	*/
    sh_int	buy_type[MAX_TRADE];	/* Item types shop will buy	*/
    sh_int	profit_buy;		/* Cost multiplier for buying	*/
    sh_int	profit_sell;		/* Cost multiplier for selling	*/
    sh_int	open_hour;		/* First opening hour		*/
    sh_int	close_hour;		/* First closing hour		*/
};

#define MAX_FIX		3
#define SHOP_FIX	1
#define SHOP_RECHARGE	2

struct	repairshop_data
{
    REPAIR_DATA* next;			/* Next shop in list		*/
    REPAIR_DATA* prev;			/* Previous shop in list	*/
    int		  keeper;		/* Vnum of shop keeper mob	*/
    sh_int	  fix_type[MAX_FIX];	/* Item types shop will fix	*/
    sh_int	  profit_fix;		/* Cost multiplier for fixing	*/
    sh_int	  shop_type;		/* Repair shop type		*/
    sh_int	  open_hour;		/* First opening hour		*/
    sh_int	  close_hour;		/* First closing hour		*/
};


/* Mob program structures */
struct  act_prog_data
{
    struct act_prog_data* next;
    void* vo;
};

struct	mob_prog_act_list
{
    MPROG_ACT_LIST* next;
    char* buf;
    CHAR_DATA* ch;
    OBJ_DATA* obj;
    void* vo;
};

struct	mob_prog_data
{
    MPROG_DATA* next;
    int		 type;
    bool	 triggered;
    int		 resetdelay;
    char* arglist;
    char* comlist;
};

bool	MOBtrigger;

typedef enum { PLAYER_SHIP, MOB_SHIP } ship_types;
typedef enum {
    SHIP_DOCKED, SHIP_READY, SHIP_BUSY, SHIP_BUSY_2, SHIP_BUSY_3, SHIP_REFUEL,
    SHIP_LAUNCH, SHIP_LAUNCH_2, SHIP_LAND, SHIP_LAND_2, SHIP_HYPERSPACE, SHIP_DISABLED, SHIP_FLYING
} ship_states;
typedef enum { MISSILE_READY, MISSILE_FIRED, MISSILE_RELOAD, MISSILE_RELOAD_2, MISSILE_DAMAGED } missile_states;
typedef enum { SPACECRAFT, SPACE_STATION, AIRCRAFT, BOAT, SUBMARINE, LAND_VEHICLE } ship_classes;

typedef enum {
    FIGHTER1, SHUTTLE1, TRANSPORT1,
    FIGHTER2, SHUTTLE2, TRANSPORT2,
    CORVETTE, FRIGATE, DESTROYER,
    CRUISER, BATTLESHIP, FLAGSHIP,
    CUSTOM_SHIP
} ship_models;
typedef enum { MOB_PATROL = 0, MOB_DESTROYER = 6, MOB_CRUISER = 8, MOB_BATTLESHIP = 10 } mob_ship_models;

#define MAX_SHIP_MODEL	CUSTOM_SHIP

struct	model_type
{
    char* name;
    sh_int      hyperspeed;
    sh_int      realspeed;
    sh_int      missiles;
    sh_int      lasers;
    sh_int      tractorbeam;
    sh_int      manuever;
    int         energy;
    int         shield;
    int         hull;
    sh_int      rooms;
};

#define LASER_DAMAGED    -1
#define LASER_READY       0

#define NEWBIE_STARSYSTEM 	"Terra Prime"

struct space_data
{
    SPACE_DATA* next;
    SPACE_DATA* prev;
    SHIP_DATA* first_ship;
    SHIP_DATA* last_ship;
    MISSILE_DATA* first_missile;
    MISSILE_DATA* last_missile;
    PLANET_DATA* first_planet;
    PLANET_DATA* last_planet;
    char* filename;
    char* name;
    char* star1;
    char* star2;
    int          s1x;
    int          s1y;
    int          s1z;
    int          s2x;
    int          s2y;
    int          s2z;
    int          crash;
};

struct guard_data
{
    GUARD_DATA* next;
    GUARD_DATA* prev;
    GUARD_DATA* next_on_planet;
    GUARD_DATA* prev_on_planet;
    CHAR_DATA* mob;
    ROOM_INDEX_DATA* reset_loc;
    PLANET_DATA* planet;
};

struct  planet_data
{
    PLANET_DATA* next;
    PLANET_DATA* prev;
    PLANET_DATA* next_in_system;
    PLANET_DATA* prev_in_system;
    GUARD_DATA* first_guard;
    GUARD_DATA* last_guard;
    SPACE_DATA* starsystem;
    AREA_DATA* area;
    char* name;
    char* filename;
    CLAN_DATA* governed_by;
    int 	     population;
    float            pop_support;
    int		     sector;
    int 	     x, y, z;
    int              size;
    int		     citysize;
    int              wilderness;
    int		     wildlife;
    int		     farmland;
    int		     barracks;
    int		     controls;

    /**
     * @brief Flags that indicate attributes of the planet.
     */
    int flags;
};

struct	clan_data
{
    CLAN_DATA* next;		/* next clan in list			*/
    CLAN_DATA* prev;		/* previous clan in list		*/
    char* filename;	/* Clan filename			*/
    char* name;		/* Clan name				*/
    char* description;	/* A brief description of the clan	*/
    char* leaders;
    char* atwar;		/* Clan name				*/
    sh_int	members;	/* Number of clan members		*/
    long int    funds;
    int         spacecraft;
    int		vehicles;
    int		salary;
    char* tmpstr;
};

struct ship_prototype_data
{
    SHIP_PROTOTYPE* next;
    SHIP_PROTOTYPE* prev;
    char* filename;
    char* name;
    char* description;
    sh_int      class;
    sh_int      model;
    sh_int      hyperspeed;
    sh_int      realspeed;
    sh_int      maxmissiles;
    sh_int      lasers;
    sh_int      tractorbeam;
    sh_int      manuever;
    int         maxenergy;
    int         maxshield;
    int         maxhull;
    sh_int      maxchaff;
};

struct turret_data
{
    TURRET_DATA* next;
    TURRET_DATA* prev;
    ROOM_INDEX_DATA* room;
    SHIP_DATA* target;
    sh_int      laserstate;
};

struct hanger_data
{
    HANGER_DATA* next;
    HANGER_DATA* prev;
    ROOM_INDEX_DATA* room;
    bool        vehicle;
    bool        bayopen;
};

struct ship_data
{
    SHIP_DATA* next;
    SHIP_DATA* prev;
    SHIP_DATA* next_in_starsystem;
    SHIP_DATA* prev_in_starsystem;
    SHIP_DATA* next_in_room;
    SHIP_DATA* prev_in_room;
    ROOM_INDEX_DATA* in_room;
    ROOM_INDEX_DATA* first_room;
    ROOM_INDEX_DATA* last_room;
    ROOM_INDEX_DATA* pilotseat;
    ROOM_INDEX_DATA* gunseat;
    ROOM_INDEX_DATA* viewscreen;
    ROOM_INDEX_DATA* engine;
    ROOM_INDEX_DATA* entrance;
    SPACE_DATA* starsystem;
    TURRET_DATA* first_turret;
    TURRET_DATA* last_turret;
    HANGER_DATA* first_hanger;
    HANGER_DATA* last_hanger;
    char* filename;
    char* name;
    char* home;
    char* description[MAX_SHIP_ROOMS];
    char* owner;
    char* pilot;
    char* copilot;
    char* dest;
    sh_int      type;
    sh_int      class;
    sh_int      model;
    sh_int      hyperspeed;
    int         hyperdistance;
    sh_int      realspeed;
    sh_int	currspeed;
    sh_int      shipstate;
    sh_int      laserstate;
    sh_int      missilestate;
    sh_int      missiles;
    sh_int      maxmissiles;
    sh_int      lasers;
    sh_int      tractorbeam;
    sh_int      manuever;
    bool        hatchopen;
    bool 	autorecharge;
    bool        autotrack;
    bool 	autospeed;
    float       vx, vy, vz;
    float       hx, hy, hz;
    float       jx, jy, jz;
    int         maxenergy;
    int         energy;
    int         shield;
    int         maxshield;
    int         hull;
    int         maxhull;
    int         location;
    int         lastdoc;
    int         shipyard;
    long        collision;
    SHIP_DATA* target;
    SPACE_DATA* currjump;
    sh_int      chaff;
    sh_int      maxchaff;
    bool        chaff_released;
    bool        autopilot;
};



struct missile_data
{
    MISSILE_DATA* next;
    MISSILE_DATA* prev;
    MISSILE_DATA* next_in_starsystem;
    MISSILE_DATA* prev_in_starsystem;
    SPACE_DATA* starsystem;
    SHIP_DATA* target;
    SHIP_DATA* fired_from;
    char* fired_by;
    sh_int      age;
    int         speed;
    int         mx, my, mz;
};


/*
 * Data structure for notes.
 */
struct	note_data
{
    NOTE_DATA* next;
    NOTE_DATA* prev;
    char* sender;
    char* date;
    char* to_list;
    char* subject;
    int         voting;
    char* yesvotes;
    char* novotes;
    char* abstentions;
    char* text;
};

struct	board_data
{
    BOARD_DATA* next;			/* Next board in list		   */
    BOARD_DATA* prev;			/* Previous board in list	   */
    NOTE_DATA* first_note;		/* First note on board		   */
    NOTE_DATA* last_note;		/* Last note on board		   */
    char* note_file;		/* Filename to save notes to	   */
    char* read_group;		/* Can restrict a board to a       */
    char* post_group;		/* council, clan, guild etc        */
    char* extra_readers;		/* Can give read rights to players */
    char* extra_removers;        /* Can give remove rights to players */
    int		 board_obj;		/* Vnum of board object		   */
    sh_int	 num_posts;		/* Number of notes on this board   */
    sh_int	 min_read_level;	/* Minimum level to read a note	   */
    sh_int	 min_post_level;	/* Minimum level to post a note    */
    sh_int	 min_remove_level;	/* Minimum level to remove a note  */
    sh_int	 max_posts;		/* Maximum amount of notes allowed */
    int          type;                  /* Normal board or mail board? */
};


/*
 * An affect.
 */
struct	affect_data
{
    AFFECT_DATA* next;
    AFFECT_DATA* prev;
    sh_int		type;
    sh_int		duration;
    sh_int		location;
    int			modifier;
    int			bitvector;
};


/*
 * A SMAUG spell
 */
struct	smaug_affect
{
    SMAUG_AFF* next;
    char* duration;
    sh_int		location;
    char* modifier;
    int			bitvector;
};

/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (Start of section ... start here)                     *
 *                                                                         *
 ***************************************************************************/

/*
 * Well known mob virtual numbers.
 * Defined in #MOBILES.
 */
#define MOB_VNUM_SOLDIER		3
#define MOB_VNUM_GUARD			4
#define MOB_VNUM_PATROL			5
#define MOB_VNUM_TRADER			6
#define MOB_VNUM_SPACEPORT_GUARD	7
#define MOB_VNUM_BIRD			8
#define MOB_VNUM_SCAVENGER		9
#define MOB_VNUM_INSECT			10
#define MOB_VNUM_PREDITOR		11
#define MOB_VNUM_SMALL_ANIMAL		12
#define MOB_VNUM_FISH			13
#define MOB_VNUM_CITIZEN		14
#define MOB_VNUM_SUPPLIER 		15
#define MOB_VNUM_WAITER 		16
#define MOB_VNUM_CONTROLLER		17
#define MOB_VNUM_BARTENDER		18
#define MOB_VNUM_MECHANIC		19
#define MOB_VNUM_PAWNER			20
#define MOB_VNUM_TECHNICIAN		21
#define MOB_VNUM_DEALER			22
#define MOB_VNUM_VENDOR			23
#define MOB_VNUM_DRAGON			24
#define MOB_VNUM_THIEF			25
#define MOB_VNUM_THUG			26
#define MOB_VNUM_BUM			27
#define MOB_VNUM_SHIP_GUARD		28
#define MOB_VNUM_ALIEN			29
#define MOB_VNUM_JOB_OFFICER		30

/*
 * ACT bits for mobs.
 * Used in #MOBILES.
 */
#define ACT_IS_NPC		 BV00		/* Auto set for mobs	*/
#define ACT_SENTINEL		 BV01		/* Stays in one room	*/
#define ACT_SCAVENGER		 BV02		/* Picks up objects	*/
#define ACT_AGGRESSIVE		 BV05		/* Attacks PC's		*/
#define ACT_STAY_AREA		 BV06		/* Won't leave area	*/
#define ACT_WIMPY		 BV07		/* Flees when hurt	*/
#define ACT_PET			 BV08		/* Auto set for pets	*/
#define ACT_TRAIN		 BV09		/* Can train PC's	*/
#define ACT_PRACTICE		 BV10		/* Can practice PC's	*/
#define ACT_IMMORTAL		 BV11		/* Cannot be killed	*/
#define ACT_DEADLY		 BV12		/* Has a deadly poison  */
#define ACT_POLYSELF		 BV13
#define ACT_META_AGGR		 BV14		/* Extremely aggressive */
#define ACT_GUARDIAN		 BV15		/* Protects master	*/
#define ACT_RUNNING		 BV16		/* Hunts quickly	*/
#define ACT_NOWANDER		 BV17		/* Doesn't wander	*/
#define ACT_MOUNTABLE		 BV18		/* Can be mounted	*/
#define ACT_MOUNTED		 BV19		/* Is mounted		*/
#define ACT_CITIZEN              BV20           /* affects planet population as opposed to wildlife */
#define ACT_SECRETIVE		 BV21		/* actions aren't seen	*/
#define ACT_POLYMORPHED		 BV22		/* Mob is a ch		*/
#define ACT_MOBINVIS		 BV23		/* Like wizinvis	*/
#define ACT_NOASSIST		 BV24		/* Doesn't assist mobs	*/
#define ACT_NOKILL               BV25           /* Mob can't die */
#define ACT_DROID                BV26           /* mob is a droid */
#define ACT_NOCORPSE             BV27           
#define ACT_PROTOTYPE		 BV30		/* A prototype mob	*/

/*
 * Bits for 'affected_by'.
 * Used in #MOBILES.
 */
#define AFF_NONE                  0 

#define AFF_BLIND		  BV00
#define AFF_INVISIBLE		  BV01
#define AFF_DETECT_EVIL		  BV02
#define AFF_DETECT_INVIS	  BV03
#define AFF_DETECT_MAGIC	  BV04
#define AFF_DETECT_HIDDEN	  BV05
#define AFF_WEAKEN		  BV06		
#define AFF_SANCTUARY		  BV07
#define AFF_FAERIE_FIRE		  BV08
#define AFF_INFRARED		  BV09
#define AFF_CURSE		  BV10
#define AFF_FLAMING		  BV11		/* Unused	*/
#define AFF_POISON		  BV12
#define AFF_PROTECT		  BV13
#define AFF_PARALYSIS		  BV14
#define AFF_SNEAK		  BV15
#define AFF_HIDE		  BV16
#define AFF_SLEEP		  BV17
#define AFF_CHARM		  BV18
#define AFF_FLYING		  BV19
#define AFF_PASS_DOOR		  BV20
#define AFF_FLOATING		  BV21
#define AFF_TRUESIGHT		  BV22
#define AFF_DETECTTRAPS		  BV23
#define AFF_SCRYING	          BV24
#define AFF_FIRESHIELD	          BV25
#define AFF_SHOCKSHIELD	          BV26
#define AFF_HAUS1                 BV27        /* not used */
#define AFF_ICESHIELD  		  BV28
#define AFF_POSSESS		  BV29
#define AFF_BERSERK		  BV30
#define AFF_AQUA_BREATH		  BV31

/* 31 aff's (1 left.. :P) */
/* make that none - ugh - time for another field? :P */
/*
 * Resistant Immune Susceptible flags
 */
#define RIS_FIRE		  BV00
#define RIS_COLD		  BV01
#define RIS_ELECTRICITY		  BV02
#define RIS_ENERGY		  BV03
#define RIS_BLUNT		  BV04
#define RIS_PIERCE		  BV05
#define RIS_SLASH		  BV06
#define RIS_ACID		  BV07
#define RIS_POISON		  BV08
#define RIS_DRAIN		  BV09
#define RIS_SLEEP		  BV10
#define RIS_CHARM		  BV11
#define RIS_HOLD		  BV12
#define RIS_NONMAGIC		  BV13
#define RIS_PLUS1		  BV14
#define RIS_PLUS2		  BV15
#define RIS_PLUS3		  BV16
#define RIS_PLUS4		  BV17
#define RIS_PLUS5		  BV18
#define RIS_PLUS6		  BV19
#define RIS_MAGIC		  BV20
#define RIS_PARALYSIS		  BV21
/* 21 RIS's*/

/*
 * Attack types
 */
#define ATCK_BITE		  BV00
#define ATCK_CLAWS		  BV01
#define ATCK_TAIL		  BV02
#define ATCK_STING		  BV03
#define ATCK_PUNCH		  BV04
#define ATCK_KICK		  BV05
#define ATCK_TRIP		  BV06
#define ATCK_BASH		  BV07
#define ATCK_STUN		  BV08
#define ATCK_GOUGE		  BV09
#define ATCK_BACKSTAB		  BV10
#define ATCK_FEED		  BV11
#define ATCK_DRAIN		  BV12
#define ATCK_FIREBREATH		  BV13
#define ATCK_FROSTBREATH	  BV14
#define ATCK_ACIDBREATH		  BV15
#define ATCK_LIGHTNBREATH	  BV16
#define ATCK_GASBREATH		  BV17
#define ATCK_POISON		  BV18
#define ATCK_NASTYPOISON	  BV19
#define ATCK_GAZE		  BV20
#define ATCK_BLINDNESS		  BV21
#define ATCK_CAUSESERIOUS	  BV22
#define ATCK_EARTHQUAKE		  BV23
#define ATCK_CAUSECRITICAL	  BV24
#define ATCK_CURSE		  BV25
#define ATCK_FLAMESTRIKE	  BV26
#define ATCK_HARM		  BV27
#define ATCK_FIREBALL		  BV28
#define ATCK_COLORSPRAY		  BV29
#define ATCK_WEAKEN		  BV30
#define ATCK_SPIRALBLAST	  BV31
/* 32 USED! DO NOT ADD MORE! SB */

/*
 * Defense types
 */
#define DFND_PARRY		  BV00
#define DFND_DODGE		  BV01
#define DFND_HEAL		  BV02
#define DFND_CURELIGHT		  BV03
#define DFND_CURESERIOUS	  BV04
#define DFND_CURECRITICAL	  BV05
#define DFND_DISPELMAGIC	  BV06
#define DFND_DISPELEVIL		  BV07
#define DFND_SANCTUARY		  BV08
#define DFND_FIRESHIELD		  BV09
#define DFND_SHOCKSHIELD	  BV10
#define DFND_SHIELD		  BV11
#define DFND_BLESS		  BV12
#define DFND_STONESKIN		  BV13
#define DFND_TELEPORT		  BV14
#define DFND_MONSUM1		  BV15
#define DFND_MONSUM2		  BV16
#define DFND_MONSUM3		  BV17
#define DFND_MONSUM4		  BV18
#define DFND_DISARM		  BV19
#define DFND_ICESHIELD 		  BV20
#define DFND_GRIP		  BV21
/* 21 def's */

/*
 * Body parts
 */
#define PART_HEAD		  BV00
#define PART_ARMS		  BV01
#define PART_LEGS		  BV02
#define PART_HEART		  BV03
#define PART_BRAINS		  BV04
#define PART_GUTS		  BV05
#define PART_HANDS		  BV06
#define PART_FEET		  BV07
#define PART_FINGERS		  BV08
#define PART_EAR		  BV09
#define PART_EYE		  BV10
#define PART_LONG_TONGUE	  BV11
#define PART_EYESTALKS		  BV12
#define PART_TENTACLES		  BV13
#define PART_FINS		  BV14
#define PART_WINGS		  BV15
#define PART_TAIL		  BV16
#define PART_SCALES		  BV17
/* for combat */
#define PART_CLAWS		  BV18
#define PART_FANGS		  BV19
#define PART_HORNS		  BV20
#define PART_TUSKS		  BV21
#define PART_TAILATTACK		  BV22
#define PART_SHARPSCALES	  BV23
#define PART_BEAK		  BV24

#define PART_HAUNCH		  BV25
#define PART_HOOVES		  BV26
#define PART_PAWS		  BV27
#define PART_FORELEGS		  BV28
#define PART_FEATHERS		  BV29

/*
 * Autosave flags
 */
#define SV_DEATH		  BV00
#define SV_KILL			  BV01
#define SV_PASSCHG		  BV02
#define SV_DROP			  BV03
#define SV_PUT			  BV04
#define SV_GIVE			  BV05
#define SV_AUTO			  BV06
#define SV_ZAPDROP		  BV07
#define SV_AUCTION		  BV08
#define SV_GET			  BV09
#define SV_RECEIVE		  BV10
#define SV_IDLE			  BV11
#define SV_BACKUP		  BV12

/*
 * Skill/Spell flags	The minimum BV *MUST* be 11!
 */
#define SF_WATER		  BV11
#define SF_EARTH		  BV12
#define SF_AIR			  BV13
#define SF_ASTRAL		  BV14
#define SF_AREA			  BV15  /* is an area spell		*/
#define SF_DISTANT		  BV16  /* affects something far away	*/
#define SF_REVERSE		  BV17
#define SF_SAVE_HALF_DAMAGE	  BV18  /* save for half damage		*/
#define SF_SAVE_NEGATES		  BV19  /* save negates affect		*/
#define SF_ACCUMULATIVE		  BV20  /* is accumulative		*/
#define SF_RECASTABLE		  BV21  /* can be refreshed		*/
#define SF_NOSCRIBE		  BV22  /* cannot be scribed		*/
#define SF_NOBREW		  BV23  /* cannot be brewed		*/
#define SF_GROUPSPELL		  BV24  /* only affects group members	*/
#define SF_OBJECT		  BV25	/* directed at an object	*/
#define SF_CHARACTER		  BV26  /* directed at a character	*/
#define SF_SECRETSKILL		  BV27	/* hidden unless learned	*/
#define SF_PKSENSITIVE		  BV28	/* much harder for plr vs. plr	*/
#define SF_STOPONFAIL		  BV29	/* stops spell on first failure */

typedef enum {
    SS_NONE, SS_POISON_DEATH, SS_ROD_WANDS, SS_PARA_PETRI,
    SS_BREATH, SS_SPELL_STAFF
} save_types;

#define ALL_BITS		INT_MAX
#define SDAM_MASK		ALL_BITS & ~(BV00 | BV01 | BV02)
#define SACT_MASK		ALL_BITS & ~(BV03 | BV04 | BV05)
#define SCLA_MASK		ALL_BITS & ~(BV06 | BV07 | BV08)
#define SPOW_MASK		ALL_BITS & ~(BV09 | BV10)

typedef enum {
    SD_NONE, SD_FIRE, SD_COLD, SD_ELECTRICITY, SD_ENERGY, SD_ACID,
    SD_POISON, SD_DRAIN
} spell_dam_types;

typedef enum {
    SA_NONE, SA_CREATE, SA_DESTROY, SA_RESIST, SA_SUSCEPT,
    SA_DIVINATE, SA_OBSCURE, SA_CHANGE
} spell_act_types;

typedef enum { SP_NONE, SP_MINOR, SP_GREATER, SP_MAJOR } spell_power_types;

typedef enum {
    SC_NONE, SC_LUNAR, SC_SOLAR, SC_TRAVEL, SC_SUMMON,
    SC_LIFE, SC_DEATH, SC_ILLUSION
} spell_class_types;

/*
 * Sex.
 * Used in #MOBILES.
 */
typedef enum { SEX_NEUTRAL, SEX_MALE, SEX_FEMALE } sex_types;

/*
 * Well known object virtual numbers.
 * Defined in #OBJECTS.
 */
#define OBJ_VNUM_MONEY_ONE	     1
#define OBJ_VNUM_MONEY_SOME	     2
#define OBJ_VNUM_DROID_CORPSE        3
#define OBJ_VNUM_CORPSE_NPC	     4
#define OBJ_VNUM_CORPSE_PC	     5
#define OBJ_VNUM_SCRAPS		     6
#define OBJ_VNUM_MUSHROOM	     7
#define OBJ_VNUM_LIGHT		     8
#define OBJ_VNUM_SPRING		     9
#define OBJ_VNUM_SLICE		     10
#define OBJ_VNUM_SHOPPING_BAG	     11
#define OBJ_VNUM_PROTO_LIGHTSABER    12
#define OBJ_VNUM_MESSAGE_TERMINAL    13
#define OBJ_VNUM_BLACK_POWDER	     14
#define OBJ_VNUM_NOTE		     15
#define OBJ_VNUM_MAIL_TERMINAL       16
#define OBJ_VNUM_SCHOOL_DAGGER	     18
#define OBJ_VNUM_BLASTER             17
#define OBJ_VNUM_CANTEEN             19
#define OBJ_VNUM_BACKPACK            20
#define OBJ_VNUM_PROTO_BLASTER	     21
#define OBJ_VNUM_PROTO_BLADE	     22
#define OBJ_VNUM_COMLINK             23
#define OBJ_VNUM_PROTO_ARMOR	     24
#define OBJ_VNUM_IMM_TERMINAL	     25
#define OBJ_VNUM_PROTO_SHIELD	     26
#define OBJ_VNUM_DRIED_FRUIT	     27
#define OBJ_VNUM_AMMO                28
#define OBJ_VNUM_FIRST_PART	     29  /* first randomly placed object */
#define OBJ_VNUM_LAST_PART	     38  /* last randomly placed object */

#define OBJ_VNUM_FRUIT		     51
#define OBJ_VNUM_ROOT		     52
#define OBJ_VNUM_SEAWEED	     53
#define OBJ_VNUM_PLANT		     54
#define OBJ_VNUM_HEMP		     55
#define OBJ_VNUM_RESIN		     56
#define OBJ_VNUM_CRYSTAL	     57
#define OBJ_VNUM_METAL		     58
#define OBJ_VNUM_GOLD		     59
#define OBJ_VNUM_SHOVEL		     60
#define OBJ_VNUM_BATTERY             61
#define OBJ_VNUM_APPETIZER           62
#define OBJ_VNUM_SALAD               63
#define OBJ_VNUM_LUNCH               64
#define OBJ_VNUM_DINNER              65
#define OBJ_VNUM_GLASSOFWATER        66
#define OBJ_VNUM_COFFEE              67
#define OBJ_VNUM_JUICE               68
#define OBJ_VNUM_BEER                69
#define OBJ_VNUM_WHISKEY             70
#define OBJ_VNUM_DRAGON_CRYSTAL      71
#define OBJ_VNUM_DRAGON_NEST         72
#define OBJ_VNUM_SEWKIT              73

#define OBJ_VNUM_FIRST_FABRIC        75  
#define OBJ_VNUM_LAST_FABRIC         99

#define OBJ_VNUM_PACKAGE             100

/*
 * Item types.
 * Used in #OBJECTS.
 */
typedef enum
{
    ITEM_NONE, ITEM_LIGHT, ITEM_WEAPON, ITEM_ARMOR, ITEM_FURNITURE,
    ITEM_TRASH, ITEM_CONTAINER, ITEM_PAPER, ITEM_DRINK_CON, ITEM_FOOD,
    ITEM_MONEY, ITEM_PEN, ITEM_CORPSE_NPC, ITEM_CORPSE_PC, ITEM_FOUNTAIN,
    ITEM_SCRAPS, ITEM_LOCKPICK, ITEM_AMMO, ITEM_SHOVEL, ITEM_LENS,
    ITEM_CRYSTAL, ITEM_PLASTIC, ITEM_BATTERY, ITEM_TOOLKIT, ITEM_METAL,
    ITEM_OVEN, ITEM_MIRROR, ITEM_CIRCUIT, ITEM_SUPERCONDUCTOR, ITEM_COMLINK,
    ITEM_MEDPAC, ITEM_FABRIC, ITEM_RARE_METAL, ITEM_MAGNET, ITEM_THREAD,
    ITEM_DEVICE, ITEM_DROID_CORPSE, ITEM_RESOURCE
} item_types;


#define MAX_ITEM_TYPE		     ITEM_RESOURCE
/*
 * Extra flags.
 * Used in #OBJECTS.
 */
#define ITEM_GLOW		BV00
#define ITEM_HUM		BV01
#define ITEM_DARK		BV02
#define ITEM_BV4		BV04
#define ITEM_INVIS		BV05
#define ITEM_MAGIC		BV06
#define ITEM_NODROP		BV07
#define ITEM_BLESS		BV08
#define ITEM_BV9		BV09
#define ITEM_BV10		BV10
#define ITEM_BV11		BV11
#define ITEM_NOREMOVE		BV12
#define ITEM_INVENTORY		BV13
#define ITEM_BV14		BV14
#define ITEM_BV15	        BV15
#define ITEM_BV16		BV16
#define ITEM_BV17   		BV17
#define ITEM_DONATION		BV20
#define ITEM_CLANOBJECT		BV21
#define ITEM_BV22		BV22
#define ITEM_BV23 	  	BV23
#define ITEM_BV24   	        BV24
#define ITEM_HIDDEN		BV25
#define ITEM_POISONED		BV26
#define ITEM_COVERING		BV27
#define ITEM_DEATHROT		BV28
#define ITEM_BURRIED		BV29	/* item is underground */
#define ITEM_PROTOTYPE		BV30

/* Magic flags - extra extra_flags for objects that are used in spells */
#define ITEM_RETURNING		BV00
#define ITEM_BACKSTABBER  	BV01
#define ITEM_BANE		BV02
#define ITEM_LOYAL		BV03
#define ITEM_HASTE		BV04
#define ITEM_DRAIN		BV05
#define ITEM_LIGHTNING_BLADE  	BV06

/* Blaster settings - only saves on characters */
#define BLASTER_NORMAL          0
#define BLASTER_HALF		2
#define BLASTER_FULL            5
#define BLASTER_LOW		1	
#define	BLASTER_STUN		3
#define BLASTER_HIGH            4

/* Weapon Types */

#define WEAPON_NONE     	0
#define WEAPON_VIBRO_BLADE	2
#define WEAPON_LIGHTSABER	3
#define WEAPON_BLASTER		6

#define TELE_SHOWDESC		BV00
#define TELE_TRANSALL		BV01
#define TELE_TRANSALLPLUS	BV02

/*
 * Wear flags.
 * Used in #OBJECTS.
 */
#define ITEM_TAKE		BV00
#define ITEM_WEAR_FINGER	BV01
#define ITEM_WEAR_NECK		BV02
#define ITEM_WEAR_BODY		BV03
#define ITEM_WEAR_HEAD		BV04
#define ITEM_WEAR_LEGS		BV05
#define ITEM_WEAR_FEET		BV06
#define ITEM_WEAR_HANDS		BV07
#define ITEM_WEAR_ARMS		BV08
#define ITEM_WEAR_SHIELD	BV09
#define ITEM_WEAR_ABOUT		BV10
#define ITEM_WEAR_WAIST		BV11
#define ITEM_WEAR_WRIST		BV12
#define ITEM_WIELD		BV13
#define ITEM_HOLD		BV14
#define ITEM_DUAL_WIELD		BV15
#define ITEM_WEAR_EARS		BV16
#define ITEM_WEAR_EYES		BV17
#define ITEM_MISSILE_WIELD	BV18

/**
 * Planet Flags
 */
 #define PLANET_NOINVADE    BV00

/*
 * Apply types (for affects).
 * Used in #OBJECTS.
 */
typedef enum
{
    APPLY_NONE, APPLY_STR, APPLY_DEX, APPLY_INT, APPLY_WIS, APPLY_CON,
    APPLY_SEX, APPLY_NULL, APPLY_LEVEL, APPLY_AGE, APPLY_HEIGHT, APPLY_WEIGHT,
    APPLY_MANA, APPLY_HIT, APPLY_MOVE, APPLY_GOLD, APPLY_EXP, APPLY_AC,
    APPLY_HITROLL, APPLY_DAMROLL, APPLY_SAVING_POISON, APPLY_SAVING_ROD,
    APPLY_SAVING_PARA, APPLY_SAVING_BREATH, APPLY_SAVING_SPELL, APPLY_CHA,
    APPLY_AFFECT, APPLY_RESISTANT, APPLY_IMMUNE, APPLY_SUSCEPTIBLE,
    APPLY_WEAPONSPELL, APPLY_LCK, APPLY_BACKSTAB, APPLY_PICK, APPLY_TRACK,
    APPLY_STEAL, APPLY_SNEAK, APPLY_HIDE, APPLY_PALM, APPLY_DETRAP, APPLY_DODGE,
    APPLY_PEEK, APPLY_SCAN, APPLY_GOUGE, APPLY_SEARCH, APPLY_MOUNT, APPLY_DISARM,
    APPLY_KICK, APPLY_PARRY, APPLY_BASH, APPLY_STUN, APPLY_PUNCH, APPLY_CLIMB,
    APPLY_GRIP, APPLY_SCRIBE, APPLY_BREW, APPLY_WEARSPELL, APPLY_REMOVESPELL,
    APPLY_EMOTION, APPLY_MENTALSTATE, APPLY_STRIPSN, APPLY_REMOVE, APPLY_DIG,
    APPLY_FULL, APPLY_THIRST, APPLY_DRUNK, APPLY_BLOOD, MAX_APPLY_TYPE
} apply_types;

#define REVERSE_APPLY		   1000

/*
 * Values for containers (value[1]).
 * Used in #OBJECTS.
 */
#define CONT_CLOSEABLE		      1
#define CONT_PICKPROOF		      2
#define CONT_CLOSED		      4
#define CONT_LOCKED		      8

/*
 * Well known room virtual numbers.
 * Defined in #ROOMS.
 */
#define ROOM_VNUM_LIMBO		      2
#define ROOM_LIMBO_SHIPYARD           3
#define ROOM_IMMORTAL_START           4
#define ROOM_VNUM_SCHOOL              10
#define ROOM_NEWBIE_SHIPYARD	      5
#define ROOM_VNUM_JAIL		      19

/*
 * Room flags.           Holy cow!  Talked about stripped away..
 * Used in #ROOMS.       Those merc guys know how to strip code down.
 *			 Lets put it all back... ;)
 */

#define ROOM_DARK       BV00
/* BV01 now reserved for track  BV01  and hunt */
#define ROOM_NO_MOB     BV02
#define ROOM_INDOORS    BV03
#define ROOM_CAN_LAND   BV04
#define ROOM_GARAGE     BV05
#define ROOM_CONTROL    BV06  
#define ROOM_TRADE      BV07
#define ROOM_BANK       BV08
#define R9              BV09
#define ROOM_SAFE       BV10
#define ROOM_MAIL       BV11
#define ROOM_INFO       BV12
#define R13             BV13
#define ROOM_SHIPYARD   BV14
#define ROOM_BARRACKS   BV15
#define R16             BV16
#define ROOM_NOPEDIT    BV17 /* players can't edit */
#define R18             BV18
#define ROOM_RESTAURANT BV19
#define ROOM_PLR_HOME   BV20
#define ROOM_EMPTY_HOME BV21
#define R22             BV22
#define ROOM_HOTEL      BV23
#define ROOM_NOFLOOR    BV24
#define ROOM_PAWN       BV25
#define ROOM_SUPPLY     BV26
#define ROOM_BAR        BV27
#define ROOM_EMPLOYMENT BV28
#define ROOM_SPACECRAFT BV29
#define R30             BV30
#define ROOM_AUCTION    BV31


enum dir_type
{
    DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST, DIR_UP, DIR_DOWN,
    DIR_NORTHEAST, DIR_NORTHWEST, DIR_SOUTHEAST, DIR_SOUTHWEST, DIR_SOMEWHERE,

    /**
     * @brief An unknown direction.
     */
     DIR_UNKNOWN
};

/**
 * @brief Directions. Used in #ROOMS.
 */
typedef enum dir_type DIR_TYPE;

#define MAX_DIR			DIR_SOUTHWEST	/* max for normal walking */
#define DIR_PORTAL		DIR_SOMEWHERE	/* portal direction	  */


/*
 * Exit flags.
 * Used in #ROOMS.
 */
#define EX_ISDOOR		  BV00
#define EX_CLOSED		  BV01
#define EX_LOCKED		  BV02
#define EX_SECRET		  BV03
#define EX_SWIM			  BV04
#define EX_PICKPROOF		  BV05
#define EX_FLY			  BV06
#define EX_CLIMB		  BV07
#define EX_DIG			  BV08
#define EX_RES1                   BV09	/* are these res[1-4] important? */
#define EX_NOPASSDOOR		  BV10
#define EX_HIDDEN		  BV11
#define EX_PASSAGE		  BV12
#define EX_PORTAL 		  BV13
#define EX_RES2			  BV14
#define EX_RES3			  BV15
#define EX_xCLIMB		  BV16
#define EX_xENTER		  BV17
#define EX_xLEAVE		  BV18
#define EX_xAUTO		  BV19
#define EX_RES4	  		  BV20
#define EX_xSEARCHABLE		  BV21
#define EX_BASHED                 BV22
#define EX_BASHPROOF              BV23
#define EX_NOMOB		  BV24
#define EX_WINDOW		  BV25
#define EX_xLOOK		  BV26
#define MAX_EXFLAG		  26

/*
 * Sector types.
 * Used in #ROOMS.
 */
typedef enum
{
    SECT_INSIDE, SECT_CITY, SECT_FIELD, SECT_FOREST, SECT_HILLS, SECT_MOUNTAIN,
    SECT_WATER_SWIM, SECT_WATER_NOSWIM, SECT_UNDERWATER, SECT_AIR, SECT_DESERT,
    SECT_DUNNO, SECT_OCEANFLOOR, SECT_UNDERGROUND, SECT_SCRUB, SECT_ROCKY,
    SECT_SAVANNA, SECT_TUNDRA, SECT_GLACIAL, SECT_RAINFOREST, SECT_JUNGLE,
    SECT_SWAMP, SECT_WETLANDS, SECT_BRUSH, SECT_STEPPE, SECT_FARMLAND, SECT_VOLCANIC,
    SECT_MAX
} sector_types;

/*
 * Equpiment wear locations.
 * Used in #RESETS.
 */
typedef enum
{
    WEAR_NONE = -1, WEAR_LIGHT = 0, WEAR_FINGER_L, WEAR_FINGER_R, WEAR_NECK_1,
    WEAR_NECK_2, WEAR_BODY, WEAR_HEAD, WEAR_LEGS, WEAR_FEET, WEAR_HANDS,
    WEAR_ARMS, WEAR_SHIELD, WEAR_ABOUT, WEAR_WAIST, WEAR_WRIST_L, WEAR_WRIST_R,
    WEAR_WIELD, WEAR_HOLD, WEAR_DUAL_WIELD, WEAR_EARS, WEAR_EYES,
    WEAR_MISSILE_WIELD, MAX_WEAR
} wear_locations;

/* Board Types */
typedef enum { BOARD_NOTE, BOARD_MAIL } board_types;

/* Auth Flags */
#define FLAG_WRAUTH		      1
#define FLAG_AUTH		      2

/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (End of this section ... stop here)                   *
 *                                                                         *
 ***************************************************************************/

/*
 * Conditions.
 */
typedef enum
{
    COND_DRUNK, COND_FULL, COND_THIRST, COND_BLOODTHIRST, MAX_CONDS
} conditions;

/*
 * Positions.
 */
typedef enum
{
    POS_DEAD, POS_MORTAL, POS_INCAP, POS_STUNNED, POS_SLEEPING, POS_RESTING,
    POS_SITTING, POS_FIGHTING, POS_STANDING, POS_MOUNTED, POS_SHOVE, POS_DRAG
} positions;

/*
 * ACT bits for players.
 */
#define PLR_IS_NPC		      BV00	/* Don't EVER set.	*/
#define PLR_BOUGHT_PET		      BV01
#define PLR_SHOVEDRAG		      BV02
#define PLR_AUTOEXIT		      BV03
#define PLR_AUTOLOOT		      BV04
#define PLR_AUTOSAC                   BV05
#define PLR_BLANK		      BV06
#define PLR_OUTCAST 		      BV07
#define PLR_BRIEF		      BV08
#define PLR_COMBINE		      BV09
#define PLR_PROMPT		      BV10
#define PLR_TELNET_GA		      BV11

#define PLR_HOLYLIGHT		   BV12
#define PLR_WIZINVIS		   BV13
#define PLR_ROOMVNUM		   BV14

#define	PLR_SILENCE		   BV15
#define PLR_NO_EMOTE		   BV16
#define PLR_ATTACKER    	   BV17
#define PLR_NO_TELL		   BV18
#define PLR_LOG			   BV19
#define PLR_DENY		   BV20
#define PLR_FREEZE		   BV21
#define PLR_KILLER    	           BV22
/*
#define PLR_    	           BV23
*/
#define PLR_LITTERBUG	           BV24
#define PLR_ANSI	           BV25
#define PLR_SOUND	           BV26
#define PLR_NICE	           BV27
#define PLR_FLEE	           BV28
#define PLR_AUTOGOLD               BV29
#define PLR_AUTOMAP                BV30
#define PLR_AFK                    BV31

/* Bits for pc_data->flags. */
#define PCFLAG_R1                  BV00
/*
#define PCFLAG_                    BV01     extra flag
*/
#define PCFLAG_UNAUTHED		   BV02
#define PCFLAG_NORECALL            BV03
#define PCFLAG_NOINTRO             BV04
#define PCFLAG_GAG		   BV05
#define PCFLAG_RETIRED             BV06
#define PCFLAG_GUEST               BV07
#define PCFLAG_NOSUMMON		   BV08
#define PCFLAG_PAGERON		   BV09
#define PCFLAG_NOTITLE             BV10
#define PCFLAG_ROOM                BV11

typedef enum
{
    TIMER_NONE, TIMER_RECENTFIGHT, TIMER_SHOVEDRAG, TIMER_DO_FUN,
    TIMER_APPLIED, TIMER_PKILLED
} timer_types;

struct timer_data
{
    TIMER* prev;
    TIMER* next;
    DO_FUN* do_fun;
    int		value;
    sh_int	type;
    sh_int	count;
};


/*
 * Channel bits.
 */
#define	CHANNEL_AUCTION		   BV00
#define	CHANNEL_IMMTALK		   BV01
#define	CHANNEL_YELL		   BV02
#define CHANNEL_MONITOR		   BV03
#define CHANNEL_LOG		   BV04
#define CHANNEL_CLAN		   BV05
#define CHANNEL_BUILD		   BV06
#define CHANNEL_COMM		   BV07
#define CHANNEL_TELLS		   BV08
#define CHANNEL_NEWBIE             BV09
#define CHANNEL_OOC                BV10
#define CHANNEL_SHIP               BV11
#define CHANNEL_SYSTEM             BV12
#define CHANNEL_GNET               BV13
#define CHANNEL_PNET               BV14

#define CHANNEL_CLANTALK	   CHANNEL_CLAN

/* Area defines - Scryn 8/11
 *
 */
#define AREA_DELETED		   BV00
#define AREA_LOADED                BV01

/* Area flags - Narn Mar/96 */
#define AFLAG_NOPKILL               BV00
#define AFLAG_MODIFIED              BV01  /* signifies area needs saving */

/*
 * Prototype for a mob.
 * This is the in-memory version of #MOBILES.
 */
struct	mob_index_data
{
    MOB_INDEX_DATA* next;
    MOB_INDEX_DATA* next_sort;
    SPEC_FUN* spec_fun;
    SPEC_FUN* spec_2;
    SHOP_DATA* pShop;
    REPAIR_DATA* rShop;
    MPROG_DATA* mudprogs;
    int			progtypes;
    char* player_name;
    char* short_descr;
    char* long_descr;
    char* description;
    long 		vnum;
    sh_int		count;
    sh_int		killed;
    sh_int		sex;
    sh_int		level;
    int			act;
    int			affected_by;
    sh_int		alignment;
    sh_int		mobthac0;		/* Unused */
    sh_int		ac;
    sh_int		hitnodice;
    sh_int		hitsizedice;
    sh_int		hitplus;
    sh_int		damnodice;
    sh_int		damsizedice;
    sh_int		damplus;
    sh_int		numattacks;
    int			gold;
    int			exp;
    int			xflags;
    int			resistant;
    int			immune;
    int			susceptible;
    int			attacks;
    int			defenses;
    sh_int		position;
    sh_int		defposition;
    sh_int		height;
    sh_int		weight;
    sh_int		hitroll;
    sh_int		damroll;
    sh_int		perm_str;
    sh_int		perm_int;
    sh_int		perm_wis;
    sh_int		perm_dex;
    sh_int		perm_con;
    sh_int		perm_cha;
    sh_int		perm_lck;
    sh_int		perm_frc;
    sh_int		saving_poison_death;
    sh_int		saving_wand;
    sh_int		saving_para_petri;
    sh_int		saving_breath;
    sh_int		saving_spell_staff;
};


struct hunt_hate_fear
{
    char* name;
    CHAR_DATA* who;
};

struct fighting_data
{
    CHAR_DATA* who;
    int			xp;
    sh_int		align;
    sh_int		duration;
    sh_int		timeskilled;
};

struct	editor_data
{
    sh_int		numlines;
    sh_int		on_line;
    sh_int		size;
    char		line[49][81];
};

struct	extracted_char_data
{
    EXTRACT_CHAR_DATA* next;
    CHAR_DATA* ch;
    ROOM_INDEX_DATA* room;
    ch_ret		retcode;
    bool		extract;
};

/*
 * One character (PC or NPC).
 * (Shouldn't most of that build interface stuff use substate, dest_buf,
 * spare_ptr and tempnum?  Seems a little redundant)
 */
struct	char_data
{
    CHAR_DATA* next;
    CHAR_DATA* prev;
    CHAR_DATA* next_in_room;
    CHAR_DATA* prev_in_room;
    CHAR_DATA* master;
    CHAR_DATA* leader;
    FIGHT_DATA* fighting;
    CHAR_DATA* reply;
    CHAR_DATA* switched;
    CHAR_DATA* mount;
    HHF_DATA* hunting;
    HHF_DATA* fearing;
    HHF_DATA* hating;
    SPEC_FUN* spec_fun;
    SPEC_FUN* spec_2;
    MPROG_ACT_LIST* mpact;
    int			mpactnum;
    sh_int		mpscriptpos;
    MOB_INDEX_DATA* pIndexData;
    DESCRIPTOR_DATA* desc;
    AFFECT_DATA* first_affect;
    AFFECT_DATA* last_affect;
    NOTE_DATA* pnote;
    OBJ_DATA* first_carrying;
    OBJ_DATA* last_carrying;
    ROOM_INDEX_DATA* in_room;
    ROOM_INDEX_DATA* was_in_room;
    ROOM_INDEX_DATA* was_sentinel;
    ROOM_INDEX_DATA* plr_home;
    PC_DATA* pcdata;
    DO_FUN* last_cmd;
    DO_FUN* prev_cmd;   /* mapping */
    void* dest_buf;
    void* dest_buf_2;
    void* spare_ptr;
    long			tempnum;
    EDITOR_DATA* editor;
    TIMER* first_timer;
    TIMER* last_timer;
    char* name;
    char* short_descr;
    char* long_descr;
    char* description;
    sh_int		num_fighting;
    sh_int		substate;
    sh_int		sex;
    sh_int              top_level;
    sh_int		trust;
    int			played;
    time_t		logon;
    time_t		save_time;
    sh_int		timer;
    sh_int		wait;
    sh_int		hit;
    sh_int		max_hit;
    sh_int		mana;
    sh_int		max_mana;
    sh_int		move;
    sh_int		max_move;
    sh_int		numattacks;
    int			gold;
    int 		act;
    int			affected_by;
    int			carry_weight;
    int			carry_number;
    int			xflags;
    int			resistant;
    int			immune;
    int			susceptible;
    int			attacks;
    int			defenses;
    sh_int		saving_poison_death;
    sh_int		saving_wand;
    sh_int		saving_para_petri;
    sh_int		saving_breath;
    sh_int		saving_spell_staff;
    sh_int		alignment;
    sh_int		barenumdie;
    sh_int		baresizedie;
    sh_int		mobthac0;
    sh_int		hitroll;
    sh_int		damroll;
    sh_int		hitplus;
    sh_int		damplus;
    sh_int		position;
    sh_int		defposition;
    sh_int		height;
    sh_int		weight;
    sh_int		armor;
    sh_int		wimpy;
    int			deaf;
    sh_int		perm_str;
    sh_int		perm_int;
    sh_int		perm_wis;
    sh_int		perm_dex;
    sh_int		perm_con;
    sh_int		perm_cha;
    sh_int		perm_lck;
    sh_int		perm_frc;
    sh_int		mod_str;
    sh_int		mod_int;
    sh_int		mod_wis;
    sh_int		mod_dex;
    sh_int		mod_con;
    sh_int		mod_cha;
    sh_int		mod_lck;
    sh_int		mod_frc;
    sh_int		mental_state;		/* simplified */
    sh_int		emotional_state;	/* simplified */
    int			pagelen;                        /* BUILD INTERFACE */
    sh_int		inter_page;                     /* BUILD INTERFACE */
    sh_int		inter_type;                     /* BUILD INTERFACE */
    char* inter_editing;                 /* BUILD INTERFACE */
    long		inter_editing_vnum;             /* BUILD INTERFACE */
    sh_int		inter_substate;                 /* BUILD INTERFACE */
    int			retran;
    int			regoto;
    sh_int		mobinvis;	/* Mobinvis level SB */
    sh_int              backup_wait;	/* reinforcements */
    long                backup_mob;     /* reinforcements */
    sh_int              was_stunned;
    CLAN_DATA* mob_clan;    /* for spec_clan_guard.. set by postguard */
    GUARD_DATA* guard_data;
};


struct killed_data
{
    long		vnum;
    char		count;
};

/*
 * Data which only PC's have.
 */
struct	pc_data
{
    CLAN_DATA* clan;
    AREA_DATA* area;
    char* homepage;
    char* clan_name;
    char* pwd;
    char* email;
    char* bamfin;
    char* bamfout;
    char* rank;
    char* title;
    char* bestowments;	/* Special bestowed commands	   */
    int                 flags;		/* Whether the player is deadly and whatever else we add.      */
    int			pkills;		/* Number of pkills on behalf of clan */
    int			pdeaths;	/* Number of times pkilled (legally)  */
    long int            outcast_time;	/* The time at which the char was outcast */
    long int            restore_time;	/* The last time the char did a restore all */
    sh_int		wizinvis;	/* wizinvis level */
    sh_int		min_snoop;	/* minimum snoop level */
    sh_int		condition[MAX_CONDS];
    sh_int		learned[MAX_SKILL];
    KILLED_DATA		killed[MAX_KILLTRACK];
    sh_int		quest_number;	/* current *QUEST BEING DONE* DON'T REMOVE! */
    sh_int		quest_curr;	/* current number of quest points */
    int			quest_accum;	/* quest points accumulated in players life */
    int			auth_state;
    time_t		release_date;	/* Auto-helling.. Altrag */
    char* helled_by;
    char* bio;		/* Personal Bio */
    char* authed_by;	/* what crazy imm authed this name ;) */
    SKILLTYPE* special_skills[5]; /* personalized skills/spells */
    char* prompt;		/* User config prompts */
    char* subprompt;	/* Substate prompt */
    sh_int		pagerlen;	/* For pager (NOT menus) */
    long		bank;
    sh_int		num_skills;
    sh_int		adept_skills;
};



/*
 * Liquids.
 */
#define LIQ_WATER        0
#define LIQ_MAX		19

struct	liq_type
{
    char* liq_name;
    char* liq_color;
    sh_int	liq_affect[3];
};



/*
 * Extra description data for a room or object.
 */
struct	extra_descr_data
{
    EXTRA_DESCR_DATA* next;	/* Next in list                     */
    EXTRA_DESCR_DATA* prev;	/* Previous in list                 */
    char* keyword;              /* Keyword in look/examine          */
    char* description;          /* What to see                      */
};



/*
 * Prototype for an object.
 */
struct	obj_index_data
{
    OBJ_INDEX_DATA* next;
    OBJ_INDEX_DATA* next_sort;
    EXTRA_DESCR_DATA* first_extradesc;
    EXTRA_DESCR_DATA* last_extradesc;
    AFFECT_DATA* first_affect;
    AFFECT_DATA* last_affect;
    MPROG_DATA* mudprogs;               /* objprogs */
    int			progtypes;              /* objprogs */
    char* name;
    char* short_descr;
    char* description;
    char* action_desc;
    long		vnum;
    sh_int              level;
    sh_int		item_type;
    int			extra_flags;
    int			magic_flags; /*Need more bitvectors for spells - Scryn*/
    int			wear_flags;
    sh_int		count;
    sh_int		weight;
    int			cost;
    int			value[6];
    int			serial;
    sh_int		layers;
};


/*
 * One object.
 */
struct	obj_data
{
    OBJ_DATA* next;
    OBJ_DATA* prev;
    OBJ_DATA* next_content;
    OBJ_DATA* prev_content;
    OBJ_DATA* first_content;
    OBJ_DATA* last_content;
    OBJ_DATA* in_obj;
    CHAR_DATA* carried_by;
    EXTRA_DESCR_DATA* first_extradesc;
    EXTRA_DESCR_DATA* last_extradesc;
    AFFECT_DATA* first_affect;
    AFFECT_DATA* last_affect;
    OBJ_INDEX_DATA* pIndexData;
    ROOM_INDEX_DATA* in_room;
    char* name;
    char* short_descr;
    char* description;
    char* action_desc;
    sh_int		item_type;
    sh_int		mpscriptpos;
    int			extra_flags;
    int			magic_flags; /*Need more bitvectors for spells - Scryn*/
    int			wear_flags;
    int                 blaster_setting;
    MPROG_ACT_LIST* mpact;		/* mudprogs */
    int			mpactnum;	/* mudprogs */
    sh_int		wear_loc;
    sh_int		weight;
    int			cost;
    sh_int		level;
    sh_int		timer;
    int			value[6];
    sh_int		count;		/* support for object grouping */
    int			serial;		/* serial number	       */
};


/*
 * Exit data.
 */
struct	exit_data
{
    EXIT_DATA* prev;		/* previous exit in linked list	*/
    EXIT_DATA* next;		/* next exit in linked list	*/
    EXIT_DATA* rexit;		/* Reverse exit pointer		*/
    ROOM_INDEX_DATA* to_room;	/* Pointer to destination room	*/
    char* keyword;	/* Keywords for exit or door	*/
    char* description;	/* Description of exit		*/
    long		vnum;		/* Vnum of room exit leads to	*/
    long		rvnum;		/* Vnum of room in opposite dir	*/
    int			exit_info;	/* door states & other flags	*/
    int			key;		/* Key vnum			*/
    sh_int		vdir;		/* Physical "direction"		*/
    sh_int		distance;	/* how far to the next room	*/
};



/*
 * Area definition.
 */
struct	area_data
{
    AREA_DATA* next;
    AREA_DATA* prev;
    AREA_DATA* next_sort;
    AREA_DATA* prev_sort;
    PLANET_DATA* planet;
    ROOM_INDEX_DATA* first_room;
    ROOM_INDEX_DATA* last_room;
    char* name;
    char* filename;
    int                 flags;
};



/*
 * Used to keep track of system settings and statistics		-Thoric
 */
struct	system_data
{
    int		maxplayers;		/* Maximum players this boot   */
    int		alltimemax;		/* Maximum players ever	  */
    char* time_of_max;		/* Time of max ever */
    char* officials;		/* Elected Officials */
    bool	NO_NAME_RESOLVING;	/* Hostnames are not resolved  */
    bool    	DENY_NEW_PLAYERS;	/* New players cannot connect  */
    bool	WAIT_FOR_AUTH;		/* New players must be auth'ed */
    sh_int	max_sn;			/* Max skills */
    int		save_flags;		/* Toggles for saving conditions */
    sh_int	save_frequency;		/* How old to autosave someone */
};

struct	vote_data
{
    VOTE_DATA* next;
    VOTE_DATA* prev;
    int		type;
    int		in_favour;
    int		against;
    char* time_of_vote;
    char* player;
    char* ip_list;
    char* name_list;
};


/*
 * Room type.
 */
struct	room_index_data
{
    ROOM_INDEX_DATA* next;
    ROOM_INDEX_DATA* next_sort;
    ROOM_INDEX_DATA* next_in_area;
    ROOM_INDEX_DATA* prev_in_area;
    ROOM_INDEX_DATA* next_in_ship;
    ROOM_INDEX_DATA* prev_in_ship;
    CHAR_DATA* first_person;
    CHAR_DATA* last_person;
    OBJ_DATA* first_content;
    OBJ_DATA* last_content;
    EXTRA_DESCR_DATA* first_extradesc;
    EXTRA_DESCR_DATA* last_extradesc;
    AREA_DATA* area;
    EXIT_DATA* first_exit;
    EXIT_DATA* last_exit;
    SHIP_DATA* first_ship;
    SHIP_DATA* last_ship;
    char* name;
    MAP_DATA* map;                 /* maps */
    char* description;
    long		vnum;
    int			room_flags;
    MPROG_ACT_LIST* mpact;               /* mudprogs */
    int			mpactnum;            /* mudprogs */
    MPROG_DATA* mudprogs;            /* mudprogs */
    sh_int		mpscriptpos;
    int			progtypes;           /* mudprogs */
    sh_int		light;
    sh_int		sector_type;
    long		tele_vnum;
    sh_int		tele_delay;
    sh_int		tunnel;		     /* max people that will fit */
};

/*
 * Delayed teleport type.
 */
struct	teleport_data
{
    TELEPORT_DATA* next;
    TELEPORT_DATA* prev;
    ROOM_INDEX_DATA* room;
    sh_int		timer;
};


/*
 * Types of skill numbers.  Used to keep separate lists of sn's
 * Must be non-overlapping with spell/skill types,
 * but may be arbitrary beyond that.
 */
#define TYPE_UNDEFINED               -1
#define TYPE_HIT                     1000  /* allows for 1000 skills/spells */
#define TYPE_PERSONAL		     3000  /* allows for 1000 attack types    */

/*
 *  Target types.
 */
typedef enum
{
    TAR_IGNORE, TAR_CHAR_OFFENSIVE, TAR_CHAR_DEFENSIVE, TAR_CHAR_SELF,
    TAR_OBJ_INV
} target_types;

typedef enum
{
    SKILL_UNKNOWN, SKILL_SPELL, SKILL_SKILL, SKILL_WEAPON
} skill_types;

struct timerset
{
    int num_uses;
    struct timeval total_time;
    struct timeval min_time;
    struct timeval max_time;
};

/*
 * Skills include spells as a particular case.
 */
struct	skill_type
{
    char* name;			/* Name of skill		*/
    SPELL_FUN* spell_fun;		/* Spell pointer (for spells)	*/
    DO_FUN* skill_fun;		/* Skill pointer (for skills)	*/
    sh_int	target;			/* Legal targets		*/
    sh_int	minimum_position;	/* Position for caster / user	*/
    sh_int	slot;			/* Slot for #OBJECT loading	*/
    sh_int	min_mana;		/* Minimum mana used		*/
    sh_int	beats;			/* Rounds required to use skill	*/
    char* noun_damage;		/* Damage message		*/
    char* msg_off;		/* Wear off message		*/
    sh_int	type;			/* Spell/Skill/Weapon   	*/
    int		flags;			/* extra stuff			*/
    char* hit_char;		/* Success message to caster	*/
    char* hit_vict;		/* Success message to victim	*/
    char* hit_room;		/* Success message to room	*/
    char* miss_char;		/* Failure message to caster	*/
    char* miss_vict;		/* Failure message to victim	*/
    char* miss_room;		/* Failure message to room	*/
    char* die_char;		/* Victim death msg to caster	*/
    char* die_vict;		/* Victim death msg to victim	*/
    char* die_room;		/* Victim death msg to room	*/
    char* imm_char;		/* Victim immune msg to caster	*/
    char* imm_vict;		/* Victim immune msg to victim	*/
    char* imm_room;		/* Victim immune msg to room	*/
    char* dice;			/* Dice roll			*/
    int		value;			/* Misc value			*/
    char	saves;			/* What saving spell applies	*/
    char	difficulty;		/* Difficulty of casting/learning */
    SMAUG_AFF* affects;		/* Spell affects, if any	*/
    char* components;		/* Spell components, if any	*/
    char	participants;		/* # of required participants	*/
    struct	timerset	userec;	/* Usage record			*/
    int         alignment;              /* for jedi powers */
};


struct  auction_data
{
    OBJ_DATA* item;   /* a pointer to the item */
    CHAR_DATA* seller; /* a pointer to the seller - which may NOT quit */
    CHAR_DATA* buyer;  /* a pointer to the buyer - which may NOT quit */
    int         bet;    /* last bet - or 0 if noone has bet anything */
    sh_int      going;  /* 1,2, sold */
    sh_int      pulse;  /* how many pulses (.25 sec) until another call-out ? */
    int 	starting;
};


/*
 * These are skill_lookup return values for common skills and spells.
 */
extern sh_int   gsn_spacecraft;
extern sh_int   gsn_weaponsystems;
extern sh_int   gsn_shipmaintenance;
extern sh_int   gsn_spacecombat;
extern sh_int   gsn_shipdesign;

extern sh_int   gsn_reinforcements;
extern sh_int   gsn_postguard;

extern sh_int   gsn_quicktalk;
extern sh_int   gsn_propeganda;

extern sh_int   gsn_torture;
extern sh_int   gsn_throw;
extern sh_int   gsn_disguise;
extern sh_int   gsn_first_aid;

extern sh_int   gsn_makeblade;
extern sh_int   gsn_makejewelry;
extern sh_int   gsn_makeblaster;
extern sh_int   gsn_makelight;
extern sh_int   gsn_makecomlink;
extern sh_int   gsn_makearmor;
extern sh_int   gsn_makeshield;
extern sh_int   gsn_makecontainer;
extern sh_int   gsn_lightsaber_crafting;
extern sh_int   gsn_spice_refining;

extern sh_int   gsn_survey;
extern sh_int   gsn_landscape;
extern sh_int   gsn_construction;
extern sh_int   gsn_bridge;

extern	sh_int	gsn_backstab;
extern  sh_int  gsn_circle;
extern	sh_int	gsn_dodge;
extern	sh_int	gsn_hide;
extern	sh_int	gsn_peek;
extern	sh_int	gsn_pick_lock;
extern	sh_int	gsn_sneak;
extern	sh_int	gsn_steal;
extern	sh_int	gsn_gouge;
extern	sh_int	gsn_track;
extern	sh_int	gsn_mount;
extern  sh_int  gsn_bashdoor;
extern	sh_int	gsn_berserk;
extern	sh_int	gsn_hitall;
extern	sh_int	gsn_pickshiplock;
extern	sh_int	gsn_hijack;

extern	sh_int	gsn_disarm;
extern	sh_int	gsn_enhanced_damage;
extern	sh_int	gsn_kick;
extern	sh_int	gsn_parry;
extern	sh_int	gsn_rescue;
extern	sh_int	gsn_second_attack;
extern	sh_int	gsn_third_attack;
extern	sh_int	gsn_dual_wield;


extern	sh_int	gsn_aid;

/* used to do specific lookups */
extern	sh_int	gsn_first_spell;
extern	sh_int	gsn_first_skill;
extern	sh_int	gsn_first_weapon;
extern	sh_int	gsn_top_sn;

/* spells */
extern	sh_int	gsn_blindness;
extern	sh_int	gsn_charm_person;
extern  sh_int  gsn_aqua_breath;
extern	sh_int	gsn_invis;
extern	sh_int	gsn_mass_invis;
extern	sh_int	gsn_poison;
extern	sh_int	gsn_sleep;
extern	sh_int	gsn_stun;
extern  sh_int  gsn_possess;
extern	sh_int	gsn_fireball;
extern	sh_int	gsn_lightning_bolt;


extern  sh_int  gsn_poison_weapon;
extern	sh_int	gsn_climb;

extern	sh_int	gsn_blasters;
extern	sh_int	gsn_force_pikes;
extern	sh_int	gsn_bowcasters;
extern	sh_int	gsn_lightsabers;
extern	sh_int	gsn_vibro_blades;
extern	sh_int	gsn_flexible_arms;
extern	sh_int	gsn_talonous_arms;
extern	sh_int	gsn_bludgeons;

extern  sh_int  gsn_grip;


/*
 * Utility macros.
 */
#define UMIN(a, b)		((a) < (b) ? (a) : (b))
#define UMAX(a, b)		((a) > (b) ? (a) : (b))
#define URANGE(a, b, c)		((b) < (a) ? (a) : ((b) > (c) ? (c) : (b)))
#define LOWER(c)		((c) >= 'A' && (c) <= 'Z' ? (c)+'a'-'A' : (c))
#define UPPER(c)		((c) >= 'a' && (c) <= 'z' ? (c)+'A'-'a' : (c))
#define IS_SET(flag, bit)	((flag) & (bit))
#define SET_BIT(var, bit)	((var) |= (bit))
#define REMOVE_BIT(var, bit)	((var) &= ~(bit))
#define TOGGLE_BIT(var, bit)	((var) ^= (bit))

/*
 * Memory allocation macros.
 */

#define CREATE(result, type, number)				\
do								\
{								\
   if (!((result) = (type *) calloc ((number), sizeof(type))))	\
	{ perror("malloc failure"); abort(); }			\
} while(0)

#define RECREATE(result,type,number)				\
do								\
{								\
  if (!((result) = (type *) realloc ((result), sizeof(type) * (number))))\
	{ perror("realloc failure"); abort(); }			\
} while(0)


#define DISPOSE(point) 						\
do								\
{								\
  if (!(point))							\
  {								\
	bug( "Freeing null pointer" ); \
	fprintf( stderr, "DISPOSEing NULL in %s, line %d\n", __FILE__, __LINE__ ); \
  }								\
  else free(point);						\
  point = NULL;							\
} while(0)

#ifdef HASHSTR
#define STRALLOC(point)		str_alloc((point))
#define QUICKLINK(point)	quick_link((point))
#define QUICKMATCH(p1, p2)	(int) (p1) == (int) (p2)
#define STRFREE(point)						\
do								\
{								\
  if (!(point))							\
  {								\
	bug( "Freeing null pointer" );	 			\
	fprintf( stderr, "STRFREEing NULL in %s, line %d\n", __FILE__, __LINE__ ); \
  }								\
  else if (str_free((point))==-1) 				\
    fprintf( stderr, "STRFREEing bad pointer in %s, line %d\n", __FILE__, __LINE__ ); \
} while(0)
#else
#define STRALLOC(point)		str_dup((point))
#define QUICKLINK(point)	str_dup((point))
#define QUICKMATCH(p1, p2)	strcmp((p1), (p2)) == 0
#define STRFREE(point)						\
do								\
{								\
  if (!(point))							\
  {								\
	bug( "Freeing null pointer" );				\
	fprintf( stderr, "STRFREEing NULL in %s, line %d\n", __FILE__, __LINE__ ); \
  }								\
  else free((point));						\
} while(0)
#endif

/* double-linked list handling macros -Thoric */

#define LINK(link, first, last, next, prev)			\
do								\
{								\
    if ( !(first) )						\
      (first)			= (link);			\
    else							\
      (last)->next		= (link);			\
    (link)->next		= NULL;				\
    (link)->prev		= (last);			\
    (last)			= (link);			\
} while(0)

#define INSERT(link, insert, first, next, prev)			\
do								\
{								\
    (link)->prev		= (insert)->prev;		\
    if ( !(insert)->prev )					\
      (first)			= (link);			\
    else							\
      (insert)->prev->next	= (link);			\
    (insert)->prev		= (link);			\
    (link)->next		= (insert);			\
} while(0)

#define UNLINK(link, first, last, next, prev)			\
do								\
{								\
    if ( !(link)->prev )					\
      (first)			= (link)->next;			\
    else							\
      (link)->prev->next	= (link)->next;			\
    if ( !(link)->next )					\
      (last)			= (link)->prev;			\
    else							\
      (link)->next->prev	= (link)->prev;			\
} while(0)


#define CHECK_LINKS(first, last, next, prev, type)		\
do {								\
  type *ptr, *pptr = NULL;					\
  if ( !(first) && !(last) )					\
    break;							\
  if ( !(first) )						\
  {								\
    bug( "CHECK_LINKS: last with NULL first!  %s.",		\
        __STRING(first) );					\
    for ( ptr = (last); ptr->prev; ptr = ptr->prev );		\
    (first) = ptr;						\
  }								\
  else if ( !(last) )						\
  {								\
    bug( "CHECK_LINKS: first with NULL last!  %s.",		\
        __STRING(first) );					\
    for ( ptr = (first); ptr->next; ptr = ptr->next );		\
    (last) = ptr;						\
  }								\
  if ( (first) )						\
  {								\
    for ( ptr = (first); ptr; ptr = ptr->next )			\
    {								\
      if ( ptr->prev != pptr )					\
      {								\
        bug( "CHECK_LINKS(%s): %p:->prev != %p.  Fixing.",	\
            __STRING(first), ptr, pptr );			\
        ptr->prev = pptr;					\
      }								\
      if ( ptr->prev && ptr->prev->next != ptr )		\
      {								\
        bug( "CHECK_LINKS(%s): %p:->prev->next != %p.  Fixing.",\
            __STRING(first), ptr, ptr );			\
        ptr->prev->next = ptr;					\
      }								\
      pptr = ptr;						\
    }								\
    pptr = NULL;						\
  }								\
  if ( (last) )							\
  {								\
    for ( ptr = (last); ptr; ptr = ptr->prev )			\
    {								\
      if ( ptr->next != pptr )					\
      {								\
        bug( "CHECK_LINKS (%s): %p:->next != %p.  Fixing.",	\
            __STRING(first), ptr, pptr );			\
        ptr->next = pptr;					\
      }								\
      if ( ptr->next && ptr->next->prev != ptr )		\
      {								\
        bug( "CHECK_LINKS(%s): %p:->next->prev != %p.  Fixing.",\
            __STRING(first), ptr, ptr );			\
        ptr->next->prev = ptr;					\
      }								\
      pptr = ptr;						\
    }								\
  }								\
} while(0)


#define ASSIGN_GSN(gsn, skill)					\
do								\
{								\
    if ( ((gsn) = skill_lookup((skill))) == -1 )		\
	fprintf( stderr, "ASSIGN_GSN: Skill %s not found.\n",	\
		(skill) );					\
} while(0)

#define CHECK_SUBRESTRICTED(ch)					\
do								\
{								\
    if ( (ch)->substate == SUB_RESTRICTED )			\
    {								\
	send_to_char( "You cannot use this command from within another command.\n\r", ch );	\
	return;							\
    }								\
} while(0)


/*
 * Character macros.
 */
#define IS_NPC(ch)		(IS_SET((ch)->act, ACT_IS_NPC))
#define IS_IMMORTAL(ch)		((ch)->top_level >= 200)
#define IS_OFFICIAL(ch)		(is_name((ch)->name,sysdata.officials))
#define IS_AFFECTED(ch, sn)	(IS_SET((ch)->affected_by, (sn)))
#define HAS_BODYPART(ch, part)	((ch)->xflags == 0 || IS_SET((ch)->xflags, (part)))

#define IS_GOOD(ch)		((ch)->alignment >= 350)
#define IS_EVIL(ch)		((ch)->alignment <= -350)
#define IS_NEUTRAL(ch)		(!IS_GOOD(ch) && !IS_EVIL(ch))

#define IS_AWAKE(ch)		((ch)->position > POS_SLEEPING)
#define GET_AC(ch)		( (ch)->armor + ( IS_AWAKE(ch) ? dex_app[get_curr_dex(ch)].defensive : 0 ) )
#define GET_HITROLL(ch)		((ch)->hitroll				    \
				    +str_app[get_curr_str(ch)].tohit	    \
				    +(2-(abs((ch)->mental_state)/10)))
#define GET_DAMROLL(ch)		((ch)->damroll                              \
				    +str_app[get_curr_str(ch)].todam	    \
				    +(((ch)->mental_state > 5		    \
				    &&(ch)->mental_state < 15) ? 1 : 0) )

#define IS_OUTSIDE(ch)		(!IS_SET(				    \
				    (ch)->in_room->room_flags,		    \
				    ROOM_INDOORS) && !IS_SET(               \
				    (ch)->in_room->room_flags,              \
				    ROOM_SPACECRAFT) )

#define IS_DRUNK(ch, drunk)     (number_percent() < \
			        ( (ch)->pcdata->condition[COND_DRUNK] \
				* 2 / (drunk) ) )

#define IS_CLANNED(ch)		(!IS_NPC((ch))				    \
				&& (ch)->pcdata->clan			    )

#define WAIT_STATE(ch, npulse)	((ch)->wait = UMAX((ch)->wait, (npulse)))


#define EXIT(ch, door)		( get_exit( (ch)->in_room, door ) )

#define CAN_GO(ch, door)	(EXIT((ch),(door))			 \
				&& (EXIT((ch),(door))->to_room != NULL)  \
                          	&& !IS_SET(EXIT((ch), (door))->exit_info, EX_CLOSED))

#define IS_VALID_SN(sn)		( (sn) >=0 && (sn) < MAX_SKILL		     \
				&& skill_table[(sn)]			     \
				&& skill_table[(sn)]->name )

#define SPELL_FLAG(skill, flag)	( IS_SET((skill)->flags, (flag)) )
#define SPELL_DAMAGE(skill)	( ((skill)->flags     ) & 7 )
#define SPELL_ACTION(skill)	( ((skill)->flags >> 3) & 7 )
#define SPELL_CLASS(skill)	( ((skill)->flags >> 6) & 7 )
#define SPELL_POWER(skill)	( ((skill)->flags >> 9) & 3 )
#define SET_SDAM(skill, val)	( (skill)->flags =  ((skill)->flags & SDAM_MASK) + ((val) & 7) )
#define SET_SACT(skill, val)	( (skill)->flags =  ((skill)->flags & SACT_MASK) + (((val) & 7) << 3) )
#define SET_SCLA(skill, val)	( (skill)->flags =  ((skill)->flags & SCLA_MASK) + (((val) & 7) << 6) )
#define SET_SPOW(skill, val)	( (skill)->flags =  ((skill)->flags & SPOW_MASK) + (((val) & 3) << 9) )

/* Retired and guest imms. */
#define IS_RETIRED(ch) (ch->pcdata && IS_SET(ch->pcdata->flags,PCFLAG_RETIRED))
#define IS_GUEST(ch) (ch->pcdata && IS_SET(ch->pcdata->flags,PCFLAG_GUEST))

/* RIS by gsn lookups. -- Altrag.
   Will need to add some || stuff for spells that need a special GSN. */

#define IS_FIRE(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_FIRE )
#define IS_COLD(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_COLD )
#define IS_ACID(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_ACID )
#define IS_ELECTRICITY(dt)	( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_ELECTRICITY )
#define IS_ENERGY(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_ENERGY )

#define IS_DRAIN(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_DRAIN )

#define IS_POISON(dt)		( IS_VALID_SN(dt) &&			     \
				SPELL_DAMAGE(skill_table[(dt)]) == SD_POISON )


#define NOT_AUTHED(ch)		(!IS_NPC(ch) && ch->pcdata->auth_state <= 3  \
			      && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED) )

#define IS_WAITING_FOR_AUTH(ch) (!IS_NPC(ch) && ch->desc		     \
			      && ch->pcdata->auth_state == 1		     \
			      && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED) ) 

/*
 * Object macros.
 */
#define CAN_WEAR(obj, part)	(IS_SET((obj)->wear_flags,  (part)))
#define IS_OBJ_STAT(obj, stat)	(IS_SET((obj)->extra_flags, (stat)))



/*
 * Description macros.
 */
#define PERS(ch, looker)	( can_see( (looker), (ch) ) ?		\
				( IS_NPC(ch) ? (ch)->short_descr	\
				: (ch)->name ) : "someone" )



#define log_string( txt )	( log_string_plus( (txt), LOG_NORMAL ) )


/*
 * Structure for a command in the command lookup table.
 */
struct	cmd_type
{
    CMDTYPE* next;
    char* name;
    DO_FUN* do_fun;
    sh_int		position;
    sh_int		level;
    sh_int		log;
    struct		timerset	userec;
};



/*
 * Structure for a social in the socials table.
 */
struct	social_type
{
    SOCIALTYPE* next;
    char* name;
    char* char_no_arg;
    char* others_no_arg;
    char* char_found;
    char* others_found;
    char* vict_found;
    char* char_auto;
    char* others_auto;
};



/*
 * Global constants.
 */
extern  time_t last_restore_all_time;
extern  time_t boot_time;  /* this should be moved down */
extern  HOUR_MIN_SEC* set_boot_time;
extern  struct  tm* new_boot_time;
extern  time_t new_boot_time_t;

extern	const	struct	model_type	model[MAX_SHIP_MODEL + 1];

extern	const	struct	str_app_type	str_app[26];
extern	const	struct	int_app_type	int_app[26];
extern	const	struct	wis_app_type	wis_app[26];
extern	const	struct	dex_app_type	dex_app[26];
extern	const	struct	con_app_type	con_app[26];
extern	const	struct	cha_app_type	cha_app[26];
extern  const	struct	lck_app_type	lck_app[26];
extern  const	struct	frc_app_type	frc_app[26];

extern	const	struct	liq_type	liq_table[LIQ_MAX];
extern	char* const			attack_table[13];

extern	char* const	skill_tname[];
extern	sh_int	const	movement_loss[SECT_MAX];
extern	char* const	dir_name[];
extern	char* const	where_name[];
extern	const	sh_int	rev_dir[];
extern	const	int	trap_door[];
extern	char* const	r_flags[];
extern	char* const	w_flags[];
extern	char* const	o_flags[];
extern	char* const	a_flags[];
extern	char* const	o_types[];
extern	char* const	a_types[];
extern	char* const	act_flags[];
extern  char* const   planet_flags[];
extern  char* const   weapon_table[13];
extern  char* const   spice_table[];
extern	char* const	plr_flags[];
extern	char* const	pc_flags[];
extern	char* const	trap_flags[];
extern	char* const	ris_flags[];
extern	char* const	trig_flags[];
extern	char* const	part_flags[];
extern	char* const	defense_flags[];
extern	char* const	attack_flags[];
extern	char* const	area_flags[];

/*
 * Global variables.
 */
extern	int	numobjsloaded;
extern	int	nummobsloaded;
extern	int	physicalobjects;
extern	int	num_descriptors;
extern	struct	system_data		sysdata;
extern	int	top_sn;
extern	int	top_vroom;

extern		CMDTYPE* command_hash[126];

extern		SKILLTYPE* skill_table[MAX_SKILL];
extern		SOCIALTYPE* social_index[27];
extern		CHAR_DATA* cur_char;
extern		ROOM_INDEX_DATA* cur_room;
extern		bool			cur_char_died;
extern		ch_ret			global_retcode;

extern		int			cur_obj;
extern		int			cur_obj_serial;
extern		bool			cur_obj_extracted;
extern		obj_ret			global_objcode;

extern		HELP_DATA* first_help;
extern		HELP_DATA* last_help;
extern		SHOP_DATA* first_shop;
extern		SHOP_DATA* last_shop;
extern		REPAIR_DATA* first_repair;
extern		REPAIR_DATA* last_repair;

extern		BAN_DATA* first_ban;
extern		BAN_DATA* last_ban;
extern		BAN_DATA* first_tban;
extern		BAN_DATA* last_tban;
extern		CHAR_DATA* first_char;
extern		CHAR_DATA* last_char;
extern		DESCRIPTOR_DATA* first_descriptor;
extern		DESCRIPTOR_DATA* last_descriptor;
extern		BOARD_DATA* first_board;
extern		BOARD_DATA* last_board;
extern		OBJ_DATA* first_object;
extern		OBJ_DATA* last_object;
extern		CLAN_DATA* first_clan;
extern		CLAN_DATA* last_clan;
extern		GUARD_DATA* first_guard;
extern		GUARD_DATA* last_guard;
extern          SHIP_DATA* first_ship;
extern          SHIP_DATA* last_ship;
extern          SHIP_PROTOTYPE* first_ship_prototype;
extern          SHIP_PROTOTYPE* last_ship_prototype;
extern          SPACE_DATA* first_starsystem;
extern          SPACE_DATA* last_starsystem;
extern          PLANET_DATA* first_planet;
extern          PLANET_DATA* last_planet;
extern          SENATE_DATA* first_senator;
extern          SENATE_DATA* last_senator;
extern          VOTE_DATA* first_poll;
extern          VOTE_DATA* last_poll;
extern		AREA_DATA* first_area;
extern		AREA_DATA* last_area;
extern		AREA_DATA* first_build;
extern		AREA_DATA* last_build;
extern		AREA_DATA* first_asort;
extern		AREA_DATA* last_asort;
extern		AREA_DATA* first_bsort;
extern		AREA_DATA* last_bsort;
extern		TELEPORT_DATA* first_teleport;
extern		TELEPORT_DATA* last_teleport;
extern		OBJ_DATA* extracted_obj_queue;
extern		EXTRACT_CHAR_DATA* extracted_char_queue;
extern		OBJ_DATA* save_equipment[MAX_WEAR][MAX_LAYERS];
extern		CHAR_DATA* quitting_char;
extern		CHAR_DATA* loading_char;
extern		CHAR_DATA* saving_char;
extern		OBJ_DATA* all_obj;

extern		char			bug_buf[];
extern		time_t			current_time;
extern		bool			fLogAll;
extern		FILE* fpReserve;
extern		FILE* fpLOG;
extern		char			log_buf[];
extern		TIME_INFO_DATA		time_info;
extern		WEATHER_DATA		weather_info;

extern          AUCTION_DATA* auction;
extern		struct act_prog_data* mob_act_list;


/*
 * Command functions.
 * Defined in act_*.c (mostly).
 */
DO_FUN do_arrest;
DO_FUN do_setwages;
DO_FUN do_war;
DO_FUN do_prototypes;
DO_FUN do_setprototype;
DO_FUN do_showprototype;
DO_FUN do_rentship;
DO_FUN do_designship;
DO_FUN do_disarm;
DO_FUN do_resign;
DO_FUN do_order;
DO_FUN do_rat;
DO_FUN do_gtell;
DO_FUN do_forget;
DO_FUN do_cast;
DO_FUN do_aassign;
DO_FUN do_shiptalk;
DO_FUN do_systemtalk;
DO_FUN do_gnet;
DO_FUN do_pnet;
DO_FUN do_bridge;
DO_FUN do_construction;
DO_FUN do_survey;
DO_FUN do_landscape;
DO_FUN do_allsave;
DO_FUN do_setplanet;
DO_FUN do_makeplanet;
DO_FUN do_planets;
DO_FUN do_teach;
DO_FUN do_quicktalk;
DO_FUN do_propeganda;
DO_FUN do_autopilot;
DO_FUN do_allspeeders;
DO_FUN do_speeders;
DO_FUN do_suicide;
DO_FUN do_bank;
DO_FUN do_hijack;
DO_FUN do_pickshiplock;
DO_FUN do_hail;
DO_FUN do_allships;
DO_FUN do_appoint;
DO_FUN do_demote;
DO_FUN do_empower;
DO_FUN do_capture;
DO_FUN do_chaff;
DO_FUN do_clan_donate;
DO_FUN do_clan_withdraw;
DO_FUN do_fly;
DO_FUN do_drive;
DO_FUN do_bomb;
DO_FUN do_setblaster;
DO_FUN do_ammo;
DO_FUN do_takedrug;
DO_FUN do_use;
DO_FUN do_tractorbeam;
DO_FUN do_makearmor;
DO_FUN do_makejewelry;
DO_FUN do_makelight;
DO_FUN do_makecomlink;
DO_FUN do_makeshield;
DO_FUN do_makecontainer;
DO_FUN do_reinforcements;
DO_FUN do_postguard;
DO_FUN do_torture;
DO_FUN do_snipe;
DO_FUN do_throw;
DO_FUN do_disguise;
DO_FUN do_first_aid;
DO_FUN do_makeblade;
DO_FUN do_makeblaster;
DO_FUN do_makelightsaber;
DO_FUN do_makespice;
DO_FUN do_closebay;
DO_FUN do_overthrow;
DO_FUN do_openbay;
DO_FUN do_autotrack;
DO_FUN do_tractorbeam;
DO_FUN do_radar;
DO_FUN do_recall;
DO_FUN do_buyship;
DO_FUN do_buyhome;
DO_FUN do_clanbuyship;
DO_FUN do_sellship;
DO_FUN do_autorecharge;
DO_FUN do_openhatch;
DO_FUN do_closehatch;
DO_FUN do_status;
DO_FUN do_info;
DO_FUN do_hyperspace;
DO_FUN do_target;
DO_FUN do_fire;
DO_FUN do_calculate;
DO_FUN do_recharge;
DO_FUN do_repairship;
DO_FUN do_addpilot;
DO_FUN do_rempilot;
DO_FUN do_trajectory;
DO_FUN do_accelerate;
DO_FUN do_launch;
DO_FUN do_land;
DO_FUN do_leaveship;
DO_FUN do_setstarsystem;
DO_FUN do_starsystems;
DO_FUN do_showstarsystem;
DO_FUN skill_notfound;
DO_FUN do_advance;
DO_FUN do_affected;
DO_FUN do_afk;
DO_FUN do_aid;
DO_FUN do_allow;
DO_FUN do_ansi;
DO_FUN do_appraise;
DO_FUN do_areas;
DO_FUN do_aset;
DO_FUN do_astat;
DO_FUN do_at;
DO_FUN do_auction;
DO_FUN do_authorize;
DO_FUN do_backstab;
DO_FUN do_balzhur;
DO_FUN do_bamfin;
DO_FUN do_bamfout;
DO_FUN do_ban;
DO_FUN do_bashdoor;
DO_FUN do_beep;
DO_FUN do_berserk;
DO_FUN do_bestow;
DO_FUN do_bestowarea;
DO_FUN do_bio;
DO_FUN do_board;
DO_FUN do_boards;
DO_FUN do_bodybag;
DO_FUN do_bounties;
DO_FUN do_bset;
DO_FUN do_bstat;
DO_FUN do_bug;
DO_FUN do_bury;
DO_FUN do_buy;
DO_FUN do_cedit;
DO_FUN do_channels;
DO_FUN do_ooc;
DO_FUN do_circle;
DO_FUN do_clans;
DO_FUN do_ships;
DO_FUN do_clantalk;
DO_FUN do_climb;
DO_FUN do_close;
DO_FUN do_cmdtable;
DO_FUN do_cmenu;
DO_FUN do_commands;
DO_FUN do_compare;
DO_FUN do_config;
DO_FUN do_consider;
DO_FUN do_credits;
DO_FUN do_cset;
DO_FUN do_deny;
DO_FUN do_description;
DO_FUN do_destro;
DO_FUN do_destroy;
DO_FUN do_dig;
DO_FUN do_disconnect;
DO_FUN do_dismount;
DO_FUN do_dmesg;
DO_FUN do_down;
DO_FUN do_drag;
DO_FUN do_drink;
DO_FUN do_drop;
DO_FUN do_east;
DO_FUN do_eat;
DO_FUN do_echo;
DO_FUN do_emote;
DO_FUN do_empty;
DO_FUN do_enter;
DO_FUN do_equipment;
DO_FUN do_examine;
DO_FUN do_exits;
DO_FUN do_fill;
DO_FUN do_fixchar;
DO_FUN do_flee;
DO_FUN do_foldarea;
DO_FUN do_follow;
DO_FUN do_for;
DO_FUN do_force;
DO_FUN do_forceclose;
DO_FUN do_form_password;
DO_FUN do_freeze;
DO_FUN do_get;
DO_FUN do_give;
DO_FUN do_glance;
DO_FUN do_gold;
DO_FUN do_goto;
DO_FUN do_gouge;
DO_FUN do_group;
DO_FUN do_hedit;
DO_FUN do_help;
DO_FUN do_hide;
DO_FUN do_hitall;
DO_FUN do_hlist;
DO_FUN do_holylight;
DO_FUN do_homepage;
DO_FUN do_hset;
DO_FUN do_immortalize;
DO_FUN do_immtalk;
DO_FUN do_induct;
DO_FUN do_inventory;
DO_FUN do_invis;
DO_FUN do_kick;
DO_FUN do_kill;
DO_FUN do_last;
DO_FUN do_leave;
DO_FUN do_level;
DO_FUN do_list;
DO_FUN do_loadarea;
DO_FUN do_loadup;
DO_FUN do_lock;
DO_FUN do_log;
DO_FUN do_look;
DO_FUN do_low_purge;
DO_FUN do_mailroom;
DO_FUN do_make;
DO_FUN do_makeboard;
DO_FUN do_makeclan;
DO_FUN do_makeship;
DO_FUN do_makeguild;
DO_FUN do_makerepair;
DO_FUN do_makeshop;
DO_FUN do_memory;
DO_FUN do_mcreate;
DO_FUN do_mfind;
DO_FUN do_minvoke;
DO_FUN do_mlist;
DO_FUN do_mount;
DO_FUN do_mset;
DO_FUN do_mstat;
DO_FUN do_murde;
DO_FUN do_murder;
DO_FUN do_mwhere;
DO_FUN do_newbiechat;
DO_FUN do_newbieset;
DO_FUN do_noemote;
DO_FUN do_noresolve;
DO_FUN do_north;
DO_FUN do_northeast;
DO_FUN do_northwest;
DO_FUN do_notell;
DO_FUN do_notitle;
DO_FUN do_noteroom;
DO_FUN do_ocreate;
DO_FUN do_ofind;
DO_FUN do_oinvoke;
DO_FUN do_oldscore;
DO_FUN do_olist;
DO_FUN do_open;
DO_FUN do_oset;
DO_FUN do_ostat;
DO_FUN do_outcast;
DO_FUN do_owhere;
DO_FUN do_pager;
DO_FUN do_password;
DO_FUN do_peace;
DO_FUN do_pick;
DO_FUN do_poison_weapon;
DO_FUN do_prompt;
DO_FUN do_pull;
DO_FUN do_purge;
DO_FUN do_push;
DO_FUN do_put;
DO_FUN do_qui;
DO_FUN do_quit;
DO_FUN do_rank;
DO_FUN do_reboo;
DO_FUN do_reboot;
DO_FUN do_recho;
DO_FUN do_redit;
DO_FUN do_regoto;
DO_FUN do_remove;
DO_FUN do_repair;
DO_FUN do_repairset;
DO_FUN do_repairshops;
DO_FUN do_repairstat;
DO_FUN do_reply;
DO_FUN do_report;
DO_FUN do_rescue;
DO_FUN do_rest;
DO_FUN do_reset;
DO_FUN do_resetship;
DO_FUN do_restore;
DO_FUN do_restoretime;
DO_FUN do_restrict;
DO_FUN do_retire;
DO_FUN do_retran;
DO_FUN do_return;
DO_FUN do_revert;
DO_FUN do_rlist;
DO_FUN do_rset;
DO_FUN do_rstat;
DO_FUN do_save;
DO_FUN do_savearea;
DO_FUN do_say;
DO_FUN do_scan;
DO_FUN do_score;
DO_FUN do_search;
DO_FUN do_sedit;
DO_FUN do_sell;
DO_FUN do_set_boot_time;
DO_FUN do_setclan;
DO_FUN do_setship;
DO_FUN do_shops;
DO_FUN do_shopset;
DO_FUN do_shopstat;
DO_FUN do_shove;
DO_FUN do_showclan;
DO_FUN do_showship;
DO_FUN do_showplanet;
DO_FUN do_shutdow;
DO_FUN do_shutdown;
DO_FUN do_silence;
DO_FUN do_sit;
DO_FUN do_skills;
DO_FUN do_sla;
DO_FUN do_slay;
DO_FUN do_sleep;
DO_FUN do_slice;
DO_FUN do_slist;
DO_FUN do_slookup;
DO_FUN do_sneak;
DO_FUN do_snoop;
DO_FUN do_sober;
DO_FUN do_socials;
DO_FUN do_south;
DO_FUN do_southeast;
DO_FUN do_southwest;
DO_FUN do_split;
DO_FUN do_sset;
DO_FUN do_stand;
DO_FUN do_steal;
DO_FUN do_switch;
DO_FUN do_tell;
DO_FUN do_time;
DO_FUN do_timecmd;
DO_FUN do_title;
DO_FUN do_track;
DO_FUN do_transfer;
DO_FUN do_trust;
DO_FUN do_typo;
DO_FUN do_unfoldarea;
DO_FUN do_unlock;
DO_FUN do_unsilence;
DO_FUN do_up;
DO_FUN do_users;
DO_FUN do_value;
DO_FUN do_visible;
DO_FUN do_vnums;
DO_FUN do_vsearch;
DO_FUN do_wake;
DO_FUN do_wear;
DO_FUN do_weather;
DO_FUN do_west;
DO_FUN do_where;
DO_FUN do_who;
DO_FUN do_whois;
DO_FUN do_wimpy;
DO_FUN do_wizhelp;
DO_FUN do_wizlist;
DO_FUN do_wizlock;
DO_FUN do_yell;
DO_FUN do_zones;

/* mob prog stuff */
DO_FUN do_mp_offer_job;
DO_FUN do_mp_close_passage;
DO_FUN do_mp_damage;
DO_FUN do_mp_restore;
DO_FUN do_mp_open_passage;
DO_FUN do_mp_practice;
DO_FUN do_mp_slay;
DO_FUN do_mpadvance;
DO_FUN do_mpasound;
DO_FUN do_mpat;
DO_FUN do_mpdream;
DO_FUN do_mp_deposit;
DO_FUN do_mp_withdraw;
DO_FUN do_mpecho;
DO_FUN do_mpechoaround;
DO_FUN do_mpechoat;
DO_FUN do_mpedit;
DO_FUN do_opedit;
DO_FUN do_rpedit;
DO_FUN do_mpforce;
DO_FUN do_mpinvis;
DO_FUN do_mpgoto;
DO_FUN do_mpjunk;
DO_FUN do_mpkill;
DO_FUN do_mpmload;
DO_FUN do_mpmset;
DO_FUN do_mpnothing;
DO_FUN do_mpoload;
DO_FUN do_mposet;
DO_FUN do_mppurge;
DO_FUN do_mpstat;
DO_FUN do_opstat;
DO_FUN do_rpstat;
DO_FUN do_mptransfer;
DO_FUN do_mpapply;
DO_FUN do_mpapplyb;
DO_FUN do_mppkset;
DO_FUN do_mpgain;

/*
 * Spell functions.
 * Defined in magic.c.
 */
SPELL_FUN spell_null;
SPELL_FUN spell_notfound;
SPELL_FUN spell_blindness;
SPELL_FUN spell_charm_person;
SPELL_FUN spell_fireball;
SPELL_FUN spell_identify;
SPELL_FUN spell_invis;
SPELL_FUN spell_lightning_bolt;
SPELL_FUN spell_poison;
SPELL_FUN spell_possess;
SPELL_FUN spell_sleep;
SPELL_FUN spell_smaug;

/*
 * Data files used by the server.
 *
 * AREA_LIST contains a list of areas to boot.
 * All files are read in completely at bootup.
 * Most output files (bug, idea, typo, shutdown) are append-only.
 *
 * The NULL_FILE is held open so that we have a stream handle in reserve,
 *   so players can go ahead and telnet to all the other descriptors.
 * Then we close it whenever we need to open a file (e.g. a save file).
 */
#define PLAYER_DIR	"../player/"	/* Player files			*/
#define BACKUP_DIR	"../backup/"    /* Backup Player files		*/
#define BOARD_DIR	"../boards/"	/* Board data dir		*/
#define CLAN_DIR	"../clans/"	/* Clan data dir		*/
#define SHIP_DIR        "../spacecraft/"
#define VOTE_DIR        "../voting/"
#define PROTOTYPE_DIR   "../prototypes/"
#define SPACE_DIR       "../planets/"    
#define PLANET_DIR      "../planets/"    
#define GUARD_DIR       "../planets/"    
#define SYSTEM_DIR	"../system/"	/* Main system files		*/
#define PROG_DIR	"mudprogs/"	/* MUDProg files		*/
#define CORPSE_DIR	"../corpses/"	/* Corpses			*/
#define NULL_FILE	"/dev/null"	/* To reserve one stream	*/

#define AREA_LIST	"area.lst"	/* List of areas		*/
#define BAN_LIST        "ban.lst"       /* List of bans                 */
#define CLAN_LIST	"clan.lst"	/* List of clans		*/
#define SHIP_LIST       "ship.lst"
#define PROTOTYPE_LIST  "prototype.lst"
#define PLANET_LIST      "planet.lst"
#define SPACE_LIST      "space.lst"
#define VOTE_LIST       "vote.lst"      

#define BOARD_FILE	"boards.txt"		/* For bulletin boards	 */
#define SHUTDOWN_FILE	"shutdown.txt"		/* For 'shutdown'	 */

#define ANSITITLE_FILE	SYSTEM_DIR "mudtitle.ans"
#define ASCTITLE_FILE	SYSTEM_DIR "mudtitle.asc"
#define BOOTLOG_FILE	SYSTEM_DIR "boot.txt"	  /* Boot up error file	 */
#define BUG_FILE	SYSTEM_DIR "bugs.txt"	  /* For 'bug' and bug( )*/
#define TYPO_FILE	SYSTEM_DIR "typos.txt"	  /* For 'typo'		 */
#define LOG_FILE	SYSTEM_DIR "log.txt"	  /* For talking in logged rooms */
#define WHO_FILE	SYSTEM_DIR "WHO"	  /* Who output file	 */
#define WEBWHO_FILE	SYSTEM_DIR "WEBWHO"	  /* WWW Who output file */
#define REQUEST_PIPE	SYSTEM_DIR "REQUESTS"	  /* Request FIFO	 */
#define SKILL_FILE	SYSTEM_DIR "skills.dat"   /* Skill table	 */
#define SOCIAL_FILE	SYSTEM_DIR "socials.dat"  /* Socials		 */
#define COMMAND_FILE	SYSTEM_DIR "commands.dat" /* Commands		 */
#define USAGE_FILE	SYSTEM_DIR "usage.txt"    /* How many people are on 
                             every half hour - trying to
                             determine best reboot time */

/*
 * Our function prototypes.
 * One big lump ... this is every function in Merc.
 */
#define CD	CHAR_DATA
#define MID	MOB_INDEX_DATA
#define OD	OBJ_DATA
#define OID	OBJ_INDEX_DATA
#define RID	ROOM_INDEX_DATA
#define SF	SPEC_FUN
#define BD	BOARD_DATA
#define CL	CLAN_DATA
#define EDD	EXTRA_DESCR_DATA
#define ED	EXIT_DATA
#define	ST	SOCIALTYPE
#define	CO	COUNCIL_DATA
#define DE	DEITY_DATA
#define SK	SKILLTYPE
#define SH      SHIP_DATA

/* act_comm.c */
void    sound_to_room(ROOM_INDEX_DATA* room, char* argument);
bool	circle_follow(CHAR_DATA* ch, CHAR_DATA* victim);
void	add_follower(CHAR_DATA* ch, CHAR_DATA* master);
void	stop_follower(CHAR_DATA* ch);
void	die_follower(CHAR_DATA* ch);
bool	is_same_group(CHAR_DATA* ach, CHAR_DATA* bch);
void	send_ansi_title(CHAR_DATA* ch);
void	send_ascii_title(CHAR_DATA* ch);
void	to_channel(const char* argument, int channel, const char* verb, sh_int level);
void  	talk_auction(char* argument);
char* translate(CHAR_DATA* ch, CHAR_DATA* victim, const char* argument);
char* obj_short(OBJ_DATA* obj);

/* act_info.c */
int	get_door(char* arg);
char* format_obj_to_char(OBJ_DATA* obj, CHAR_DATA* ch, bool fShort);
void	show_list_to_char(OBJ_DATA* list, CHAR_DATA* ch, bool fShort, bool fShowNothing);

              /* act_move.c */
void	clear_vrooms(void);
ED* find_door(CHAR_DATA* ch, char* arg, bool quiet);
ED* get_exit(ROOM_INDEX_DATA* room, sh_int dir);
ED* get_exit_to(ROOM_INDEX_DATA* room, sh_int dir, long vnum);
ED* get_exit_num(ROOM_INDEX_DATA* room, sh_int count);
ch_ret	move_char(CHAR_DATA* ch, EXIT_DATA* pexit, int fall);
void	teleport(CHAR_DATA* ch, sh_int room, int flags);
sh_int	encumbrance(CHAR_DATA* ch, sh_int move);
bool	will_fall(CHAR_DATA* ch, int fall);
int     wherehome(CHAR_DATA* ch);

/* act_obj.c */

obj_ret	damage_obj(OBJ_DATA* obj);
sh_int	get_obj_resistance(OBJ_DATA* obj);
void    save_clan_storeroom(CHAR_DATA* ch, CLAN_DATA* clan);
void    obj_fall(OBJ_DATA* obj, bool through);

/* act_wiz.c */
void              close_area(AREA_DATA* pArea);
RID* find_location(CHAR_DATA* ch, char* arg);
void    echo_to_room(sh_int AT_COLOR, ROOM_INDEX_DATA* room, char* argument);
void	echo_to_all(sh_int AT_COLOR, char* argument, sh_int tar);
void	echo_to_area(AREA_DATA* area, sh_int AT_COLOR, char* argument, sh_int tar);
void   	get_reboot_string(void);
struct tm* update_time(struct tm* old_time);
void	free_social(SOCIALTYPE* social);
void	add_social(SOCIALTYPE* social);
void	free_command(CMDTYPE* command);
void	unlink_command(CMDTYPE* command);
void	add_command(CMDTYPE* command);


/* boards.c */
void	load_boards(void);
BD* get_board(OBJ_DATA* obj);
void	free_note(NOTE_DATA* pnote);

/* build.c */
char* flag_string(int bitvector, char* const flagarray[]);
int	get_mpflag(char* flag);
int	get_dir(char* txt);
char* strip_cr(char* str);
int     get_vip_flag(char* flag);
int     get_wanted_flag(char* flag);
void    save_some_areas();

/* clans.c */
CL* get_clan(char* name);
void	load_clans(void);
void	save_clan(CLAN_DATA* clan);

/* clans.c */
void	load_polls(void);
void	save_poll(VOTE_DATA* poll);

/* planets.c */
PLANET_DATA* get_planet(char* name);
void	load_planets(void);
void	save_planet(PLANET_DATA* planet);
int     max_population(PLANET_DATA* planet);
long    get_taxes(PLANET_DATA* planet);

/* space.c */
SH* get_ship(char* name);
void         load_ships(void);
void         save_ship(SHIP_DATA* ship);
void         load_space(void);
void         save_starsystem(SPACE_DATA* starsystem);
SPACE_DATA* starsystem_from_name(char* name);
SPACE_DATA* starsystem_from_room(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_entrance(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_room(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_pilotseat(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_cockpit(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_turret(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_engine(ROOM_INDEX_DATA* room);
SHIP_DATA* ship_from_pilot(char* name);
SHIP_DATA* get_ship_here(char* name, SPACE_DATA* starsystem);
void         showstarsystem(CHAR_DATA* ch, SPACE_DATA* starsystem);
void         update_space(void);
void         recharge_ships(void);
void         move_ships(void);
void         update_bus(void);
void         update_traffic(void);
bool         check_pilot(CHAR_DATA* ch, SHIP_DATA* ship);
bool         is_rental(CHAR_DATA* ch, SHIP_DATA* ship);
void         echo_to_ship(int color, SHIP_DATA* ship, char* argument);
void         echo_to_cockpit(int color, SHIP_DATA* ship, char* argument);
void         echo_to_system(int color, SHIP_DATA* ship, char* argument, SHIP_DATA* ignore);
bool         extract_ship(SHIP_DATA* ship);
bool         ship_to_room(SHIP_DATA* ship, long vnum);
long         get_ship_value(SHIP_DATA* ship);
bool         rent_ship(CHAR_DATA* ch, SHIP_DATA* ship);
void         damage_ship(SHIP_DATA* ship, int min, int max);
void         damage_ship_ch(SHIP_DATA* ship, int min, int max, CHAR_DATA* ch);
void         destroy_ship(SHIP_DATA* ship, CHAR_DATA* ch);
void         ship_to_starsystem(SHIP_DATA* ship, SPACE_DATA* starsystem);
void         ship_from_starsystem(SHIP_DATA* ship, SPACE_DATA* starsystem);
void         new_missile(SHIP_DATA* ship, SHIP_DATA* target, CHAR_DATA* ch);
void         extract_missile(MISSILE_DATA* missile);
SHIP_DATA* ship_in_room(ROOM_INDEX_DATA* room, char* name);

/* morespace.c */
SHIP_PROTOTYPE* get_ship_prototype(char* name);
SHIP_DATA* make_ship(SHIP_PROTOTYPE* protoype);
void         load_prototypes(void);
void         save_ship_protoype(SHIP_PROTOTYPE* prototype);
long int     get_prototype_value(SHIP_PROTOTYPE* prototype);
void	     create_ship_rooms(SHIP_DATA* ship);

/* comm.c */
void	close_socket(DESCRIPTOR_DATA* dclose, bool force);
void	write_to_buffer(DESCRIPTOR_DATA* d, const char* txt, int length);
void	write_to_pager(DESCRIPTOR_DATA* d, const char* txt, int length);
void	send_to_char(const char* txt, CHAR_DATA* ch);
void	send_to_char_color(const char* txt, CHAR_DATA* ch);
void	send_to_pager(const char* txt, CHAR_DATA* ch);
void	send_to_pager_color(const char* txt, CHAR_DATA* ch);
void	set_char_color(sh_int AType, CHAR_DATA* ch);
void	set_pager_color(sh_int AType, CHAR_DATA* ch);
void	ch_printf(CHAR_DATA* ch, char* fmt, ...);
void	pager_printf(CHAR_DATA* ch, char* fmt, ...);
void	act(sh_int AType, const char* format, CHAR_DATA* ch, const void* arg1, const void* arg2, int type);

/* reset.c */
void	reset_all();

/* db.c */
void	show_file(CHAR_DATA* ch, char* filename);
char* str_dup(char const* str);
void	boot_db(void);
void	area_update(void);
void	add_char(CHAR_DATA* ch);
CD* create_mobile(MOB_INDEX_DATA* pMobIndex);
OD* create_object(OBJ_INDEX_DATA* pObjIndex, int level);
void	clear_char(CHAR_DATA* ch);
void	free_char(CHAR_DATA* ch);
char* get_extra_descr(const char* name, EXTRA_DESCR_DATA* ed);
MID* get_mob_index(long vnum);
OID* get_obj_index(long vnum);
RID* get_room_index(long vnum);
char	fread_letter(FILE* fp);
int	fread_number(FILE* fp);
char* fread_string(FILE* fp);
char* fread_string_nohash(FILE* fp);
void	fread_to_eol(FILE* fp);
char* fread_word(FILE* fp);
char* fread_line(FILE* fp);
int	number_fuzzy(int number);
int	number_range(int from, int to);
int	number_percent(void);
int	number_door(void);
int	number_bits(int width);
int	number_mm(void);
int	dice(int number, int size);
int	interpolate(int level, int value_00, int value_32);
void	smash_tilde(char* str);
void	hide_tilde(char* str);
char* show_tilde(char* str);

/**
 * @brief Case insensitive comparison of strings to determine if they are different.
 * @param astr First string to compare.
 * @param bstr Second string to compare to the first string.
 * @returns TRUE if different, FALSE if the same.
 */
bool	str_cmp(const char* astr, const char* bstr);
bool	str_prefix(const char* astr, const char* bstr);
bool	str_infix(const char* astr, const char* bstr);
bool	str_suffix(const char* astr, const char* bstr);
char* capitalize(const char* str);
char* strlower(const char* str);
char* strupper(const char* str);
char* aoran(const char* str);
void	append_file(CHAR_DATA* ch, char* file, char* str);
void	append_to_file(char* file, char* str);
void	bug(const char* str, ...);
void	log_string_plus(const char* str, sh_int log_type);
RID* make_room(long vnum);
RID* make_ship_room(SHIP_DATA* ship);
OID* make_object(long vnum, long cvnum, char* name);
MID* make_mobile(long vnum, long cvnum, char* name);
ED* make_exit(ROOM_INDEX_DATA* pRoomIndex, ROOM_INDEX_DATA* to_room, sh_int door);
void	add_help(HELP_DATA* pHelp);
void	fix_area_exits(AREA_DATA* tarea);
void	load_area_file(AREA_DATA* tarea, char* filename);
void	randomize_exits(ROOM_INDEX_DATA* room, sh_int maxdir);
void	make_wizlist(void);
void	tail_chain(void);
bool    delete_room(ROOM_INDEX_DATA* room);
bool    delete_obj(OBJ_INDEX_DATA* obj);
bool    delete_mob(MOB_INDEX_DATA* mob);
void	sort_area(AREA_DATA* pArea, bool proto);
void   load_votes(void);
void   save_votes(void);
bool is_valid_filename(const CHAR_DATA* ch, const char* directory, const char* filename);

/* build.c */
void	start_editing(CHAR_DATA* ch, char* data);
void	stop_editing(CHAR_DATA* ch);
void	edit_buffer(CHAR_DATA* ch, char* argument);
char* copy_buffer(CHAR_DATA* ch);
bool	can_rmodify(CHAR_DATA* ch, ROOM_INDEX_DATA* room);
bool	can_omodify(CHAR_DATA* ch, OBJ_DATA* obj);
bool	can_mmodify(CHAR_DATA* ch, CHAR_DATA* mob);
bool	can_medit(CHAR_DATA* ch, MOB_INDEX_DATA* mob);
void	free_area(AREA_DATA* are);
void	assign_area(CHAR_DATA* ch);
EDD* SetRExtra(ROOM_INDEX_DATA* room, char* keywords);
bool	DelRExtra(ROOM_INDEX_DATA* room, char* keywords);
EDD* SetOExtra(OBJ_DATA* obj, char* keywords);
bool	DelOExtra(OBJ_DATA* obj, char* keywords);
EDD* SetOExtraProto(OBJ_INDEX_DATA* obj, char* keywords);
bool	DelOExtraProto(OBJ_INDEX_DATA* obj, char* keywords);
void	fold_area(AREA_DATA* tarea, char* filename, bool install);
int	get_otype(char* type);
int	get_atype(char* type);
int	get_aflag(char* flag);
int	get_oflag(char* flag);
int	get_wflag(char* flag);
void    save_mobs();
void    save_objects();

/* fight.c */
int	max_fight(CHAR_DATA* ch);
void	violence_update(void);
ch_ret	multi_hit(CHAR_DATA* ch, CHAR_DATA* victim, int dt);
sh_int	ris_damage(CHAR_DATA* ch, sh_int dam, int ris);
ch_ret	damage(CHAR_DATA* ch, CHAR_DATA* victim, int dam, int dt);
void	update_pos(CHAR_DATA* victim);
void	set_fighting(CHAR_DATA* ch, CHAR_DATA* victim);
void	stop_fighting(CHAR_DATA* ch, bool fBoth);
void	free_fight(CHAR_DATA* ch);
CD* who_fighting(CHAR_DATA* ch);
void	check_killer(CHAR_DATA* ch, CHAR_DATA* victim);
void	check_attacker(CHAR_DATA* ch, CHAR_DATA* victim);
void	death_cry(CHAR_DATA* ch);
void	stop_hunting(CHAR_DATA* ch);
void	stop_hating(CHAR_DATA* ch);
void	stop_fearing(CHAR_DATA* ch);
void	start_hunting(CHAR_DATA* ch, CHAR_DATA* victim);
void	start_hating(CHAR_DATA* ch, CHAR_DATA* victim);
void	start_fearing(CHAR_DATA* ch, CHAR_DATA* victim);
bool	is_hunting(CHAR_DATA* ch, CHAR_DATA* victim);
bool	is_hating(CHAR_DATA* ch, CHAR_DATA* victim);
bool	is_fearing(CHAR_DATA* ch, CHAR_DATA* victim);
bool	is_safe(CHAR_DATA* ch, CHAR_DATA* victim);
bool	is_safe_nm(CHAR_DATA* ch, CHAR_DATA* victim);
bool	legal_loot(CHAR_DATA* ch, CHAR_DATA* victim);
bool    check_illegal_pk(CHAR_DATA* ch, CHAR_DATA* victim);
void    raw_kill(CHAR_DATA* ch, CHAR_DATA* victim);
bool	in_arena(CHAR_DATA* ch);

/* makeobjs.c */
void	make_corpse(CHAR_DATA* ch, CHAR_DATA* killer);
void	make_blood(CHAR_DATA* ch);
void	make_bloodstain(CHAR_DATA* ch);
void	make_scraps(OBJ_DATA* obj);
void	make_fire(ROOM_INDEX_DATA* in_room, sh_int timer);
OD* make_trap(int v0, int v1, int v2, int v3);
OD* create_money(int amount);

/* misc.c */
void actiondesc(CHAR_DATA* ch, OBJ_DATA* obj, void* vo);
void jedi_checks(CHAR_DATA* ch);
void jedi_bonus(CHAR_DATA* ch);
void sith_penalty(CHAR_DATA* ch);

/* mud_comm.c */
char* mprog_type_to_name(int type);

/* mud_prog.c */
#ifdef DUNNO_STRSTR
char* strstr(const char* s1, const char* s2);
#endif

void	mprog_wordlist_check(char* arg, CHAR_DATA* mob, CHAR_DATA* actor, OBJ_DATA* object, void* vo, int type);
void	mprog_percent_check(CHAR_DATA* mob, CHAR_DATA* actor, OBJ_DATA* object, void* vo, int type);
void	mprog_act_trigger(char* buf, CHAR_DATA* mob, CHAR_DATA* ch, OBJ_DATA* obj, void* vo);
void	mprog_bribe_trigger(CHAR_DATA* mob, CHAR_DATA* ch, int amount);
void	mprog_entry_trigger(CHAR_DATA* mob);
void	mprog_give_trigger(CHAR_DATA* mob, CHAR_DATA* ch, OBJ_DATA* obj);
void	mprog_greet_trigger(CHAR_DATA* mob);
void    mprog_fight_trigger(CHAR_DATA* mob, CHAR_DATA* ch);
void    mprog_hitprcnt_trigger(CHAR_DATA* mob, CHAR_DATA* ch);
void    mprog_death_trigger(CHAR_DATA* killer, CHAR_DATA* mob);
void    mprog_random_trigger(CHAR_DATA* mob);
void    mprog_speech_trigger(char* txt, CHAR_DATA* mob);
void    mprog_script_trigger(CHAR_DATA* mob);
void    mprog_hour_trigger(CHAR_DATA* mob);
void    mprog_time_trigger(CHAR_DATA* mob);
void    progbug(char* str, CHAR_DATA* mob);
void	rset_supermob(ROOM_INDEX_DATA* room);
void	release_supermob();

/* player.c */
void	set_title(CHAR_DATA* ch, char* title);

/* skills.c */
bool check_skill(CHAR_DATA* ch, char* command, char* argument);
void learn_from_success(CHAR_DATA* ch, int sn);
void learn_from_failure(CHAR_DATA* ch, int sn);
bool check_parry(CHAR_DATA* ch, CHAR_DATA* victim);
bool check_dodge(CHAR_DATA* ch, CHAR_DATA* victim);
bool check_grip(CHAR_DATA* ch, CHAR_DATA* victim);
void disarm(CHAR_DATA* ch, CHAR_DATA* victim);
void trip(CHAR_DATA* ch, CHAR_DATA* victim);
int character_skill_level(const CHAR_DATA* ch, short skill);


/* handler.c */
void    explode(OBJ_DATA* obj);
sh_int	get_trust(CHAR_DATA* ch);
sh_int	get_age(CHAR_DATA* ch);
sh_int	get_curr_str(CHAR_DATA* ch);
sh_int	get_curr_int(CHAR_DATA* ch);
sh_int	get_curr_wis(CHAR_DATA* ch);
sh_int	get_curr_dex(CHAR_DATA* ch);
sh_int	get_curr_con(CHAR_DATA* ch);
sh_int	get_curr_cha(CHAR_DATA* ch);
sh_int  get_curr_lck(CHAR_DATA* ch);
sh_int  get_curr_frc(CHAR_DATA* ch);
bool	can_take_proto(CHAR_DATA* ch);
int	can_carry_n(CHAR_DATA* ch);
int	can_carry_w(CHAR_DATA* ch);
bool	is_name(const char* str, char* namelist);
bool	is_name_prefix(const char* str, char* namelist);
bool	nifty_is_name(char* str, char* namelist);
bool	nifty_is_name_prefix(char* str, char* namelist);
void	affect_modify(CHAR_DATA* ch, AFFECT_DATA* paf, bool fAdd);
void	affect_to_char(CHAR_DATA* ch, AFFECT_DATA* paf);
void	affect_remove(CHAR_DATA* ch, AFFECT_DATA* paf);
void	affect_strip(CHAR_DATA* ch, int sn);
bool	is_affected(CHAR_DATA* ch, int sn);
void	affect_join(CHAR_DATA* ch, AFFECT_DATA* paf);
void	char_from_room(CHAR_DATA* ch);
void	char_to_room(CHAR_DATA* ch, ROOM_INDEX_DATA* pRoomIndex);
OD* obj_to_char(OBJ_DATA* obj, CHAR_DATA* ch);
void	obj_from_char(OBJ_DATA* obj);
int	apply_ac(OBJ_DATA* obj, int iWear);
OD* get_eq_char(CHAR_DATA* ch, int iWear);
void	equip_char(CHAR_DATA* ch, OBJ_DATA* obj, int iWear);
void	unequip_char(CHAR_DATA* ch, OBJ_DATA* obj);
int	count_obj_list(OBJ_INDEX_DATA* obj, OBJ_DATA* list);
void	obj_from_room(OBJ_DATA* obj);
OD* obj_to_room(OBJ_DATA* obj, ROOM_INDEX_DATA* pRoomIndex);
OD* obj_to_obj(OBJ_DATA* obj, OBJ_DATA* obj_to);
void	obj_from_obj(OBJ_DATA* obj);
void	extract_obj(OBJ_DATA* obj);
void	extract_exit(ROOM_INDEX_DATA* room, EXIT_DATA* pexit);
void	extract_room(ROOM_INDEX_DATA* room);
void	clean_room(ROOM_INDEX_DATA* room);
void	clean_obj(OBJ_INDEX_DATA* obj);
void	clean_mob(MOB_INDEX_DATA* mob);
void	extract_char(CHAR_DATA* ch, bool fPull);
CD* get_char_room(CHAR_DATA* ch, char* argument);
CD* get_char_world(CHAR_DATA* ch, char* argument);
OD* get_obj_type(OBJ_INDEX_DATA* pObjIndexData);
OD* get_obj_list(CHAR_DATA* ch, char* argument, OBJ_DATA* list);
OD* get_obj_list_rev(CHAR_DATA* ch, char* argument, OBJ_DATA* list);
OD* get_obj_carry(CHAR_DATA* ch, char* argument);
OD* get_obj_wear(CHAR_DATA* ch, char* argument);
OD* get_obj_here(CHAR_DATA* ch, char* argument);
OD* get_obj_world(CHAR_DATA* ch, char* argument);
int	get_obj_number(OBJ_DATA* obj);
int	get_obj_weight(OBJ_DATA* obj);
bool	room_is_dark(ROOM_INDEX_DATA* pRoomIndex);
bool	room_is_private(CHAR_DATA* ch, ROOM_INDEX_DATA* pRoomIndex);
bool	can_see(CHAR_DATA* ch, CHAR_DATA* victim);
bool	can_see_obj(CHAR_DATA* ch, OBJ_DATA* obj);
bool	can_drop_obj(CHAR_DATA* ch, OBJ_DATA* obj);
char* item_type_name(OBJ_DATA* obj);
char* affect_loc_name(int location);
char* affect_bit_name(int vector);
char* extra_bit_name(int extra_flags);
char* magic_bit_name(int magic_flags);
ch_ret	check_for_trap(CHAR_DATA* ch, OBJ_DATA* obj, int flag);
ch_ret	check_room_for_traps(CHAR_DATA* ch, int flag);
bool	is_trapped(OBJ_DATA* obj);
OD* get_trap(OBJ_DATA* obj);
ch_ret	spring_trap(CHAR_DATA* ch, OBJ_DATA* obj);
void	name_stamp_stats(CHAR_DATA* ch);
void	fix_char(CHAR_DATA* ch);
void	showaffect(CHAR_DATA* ch, AFFECT_DATA* paf);
void	set_cur_obj(OBJ_DATA* obj);
bool	obj_extracted(OBJ_DATA* obj);
void	queue_extracted_obj(OBJ_DATA* obj);
void	clean_obj_queue(void);
void	set_cur_char(CHAR_DATA* ch);
bool	char_died(CHAR_DATA* ch);
void	queue_extracted_char(CHAR_DATA* ch, bool extract);
void	clean_char_queue(void);
void	add_timer(CHAR_DATA* ch, sh_int type, sh_int count, DO_FUN* fun, int value);
TIMER* get_timerptr(CHAR_DATA* ch, sh_int type);
sh_int	get_timer(CHAR_DATA* ch, sh_int type);
void	extract_timer(CHAR_DATA* ch, TIMER* timer);
void	remove_timer(CHAR_DATA* ch, sh_int type);
bool	in_soft_range(CHAR_DATA* ch, AREA_DATA* tarea);
bool	in_hard_range(CHAR_DATA* ch, AREA_DATA* tarea);
bool	chance(CHAR_DATA* ch, sh_int percent);
bool 	chance_attrib(CHAR_DATA* ch, sh_int percent, sh_int attrib);
OD* clone_object(OBJ_DATA* obj);
void	split_obj(OBJ_DATA* obj, int num);
void	separate_obj(OBJ_DATA* obj);
bool	empty_obj(OBJ_DATA* obj, OBJ_DATA* destobj, ROOM_INDEX_DATA* destroom);
OD* find_obj(CHAR_DATA* ch, char* argument, bool carryonly);
bool	ms_find_obj(CHAR_DATA* ch);
void	worsen_mental_state(CHAR_DATA* ch, int mod);
void	better_mental_state(CHAR_DATA* ch, int mod);
void	add_kill(CHAR_DATA* ch, CHAR_DATA* mob);
int	times_killed(CHAR_DATA* ch, CHAR_DATA* mob);


/* interp.c */
bool	check_pos(CHAR_DATA* ch, sh_int position);
void	interpret(CHAR_DATA* ch, char* argument);
bool	is_number(char* arg);
int	number_argument(char* argument, char* arg);
char* one_argument(char* argument, char* arg_first);
char* one_argument2(char* argument, char* arg_first);
ST* find_social(char* command);
CMDTYPE* find_command(char* command);
void	hash_commands();
void	start_timer(struct timeval* stime);
time_t	end_timer(struct timeval* stime);
void	send_timer(struct timerset* vtime, CHAR_DATA* ch);
void	update_userec(struct timeval* time_used, struct timerset* userec);

/* magic.c */
bool	process_spell_components(CHAR_DATA* ch, int sn);
int	ch_slookup(CHAR_DATA* ch, const char* name);
int	find_spell(CHAR_DATA* ch, const char* name, bool know);
int	find_skill(CHAR_DATA* ch, const char* name, bool know);
int	find_weapon(CHAR_DATA* ch, const char* name, bool know);
int	skill_lookup(const char* name);
int	personal_lookup(CHAR_DATA* ch, const char* name);
int	slot_lookup(int slot);
int	bsearch_skill(const char* name, int first, int top);
int	bsearch_skill_exact(const char* name, int first, int top);
bool	saves_poison_death(int level, CHAR_DATA* victim);
bool	saves_wand(int level, CHAR_DATA* victim);
bool	saves_para_petri(int level, CHAR_DATA* victim);
bool	saves_breath(int level, CHAR_DATA* victim);
bool	saves_spell_staff(int level, CHAR_DATA* victim);
ch_ret	obj_cast_spell(int sn, int level, CHAR_DATA* ch, CHAR_DATA* victim, OBJ_DATA* obj);
int	dice_parse(CHAR_DATA* ch, int level, char* exp);
SK* get_skilltype(int sn);

/* request.c */
void	init_request_pipe(void);
void	check_requests(void);

/* save.c */
/* object saving defines for fread/write_obj. -- Altrag */
#define OS_CARRY	0
#define OS_CORPSE	1
void	save_char_obj(CHAR_DATA* ch);
void	save_clone(CHAR_DATA* ch);
bool	load_char_obj(DESCRIPTOR_DATA* d, char* name, bool preload);
void	set_alarm(long seconds);
void	requip_char(CHAR_DATA* ch);
void    fwrite_obj(CHAR_DATA* ch, OBJ_DATA* obj, FILE* fp, int iNest, sh_int os_type);
void	fread_obj(CHAR_DATA* ch, FILE* fp, sh_int os_type);
void	de_equip_char(CHAR_DATA* ch);
void	re_equip_char(CHAR_DATA* ch);
void	save_home(CHAR_DATA* ch);

/* shops.c */

/* special.c */
SF* spec_lookup(const char* name);
char* lookup_spec(SPEC_FUN* special);

/* tables.c */
int	get_skill(char* skilltype);
char* spell_name(SPELL_FUN* spell);
char* skill_name(DO_FUN* skill);
void	load_skill_table(void);
void	save_skill_table(void);
void	sort_skill_table(void);
void	load_socials(void);
void	save_socials(void);
void	load_commands(void);
void	save_commands(void);
SPELL_FUN* spell_function(char* name);
DO_FUN* skill_function(char* name);

/* track.c */
void	found_prey(CHAR_DATA* ch, CHAR_DATA* victim);
void	hunt_victim(CHAR_DATA* ch);

/* update.c */
void	gain_condition(CHAR_DATA* ch, int iCond, int value);
void	update_handler(void);
void	reboot_check(time_t reset);
#if 0
void    reboot_check(char* arg);
#endif
void    auction_update(void);
void	remove_portal(OBJ_DATA* portal);

/* hashstr.c */
char* str_alloc(char* str);
char* quick_link(char* str);
int	str_free(char* str);
void	show_hash(int count);
char* hash_stats(void);
char* check_hash(char* str);
void	hash_dump(int hash);
void	show_high_hash(int top);

/* newscore.c */

#undef	SK
#undef	CO
#undef	ST
#undef	CD
#undef	MID
#undef	OD
#undef	OID
#undef	RID
#undef	SF
#undef	BD 
#undef	CL
#undef	EDD
#undef	ED

/*
 *
 *  New Build Interface Stuff Follows
 *
 */


/*
 *  Data for a menu page
 */
struct	menu_data
{
    char* sectionNum;
    char* charChoice;
    int			x;
    int			y;
    char* outFormat;
    void* data;
    int			ptrType;
    int			cmdArgs;
    char* cmdString;
};

DO_FUN do_redraw_page;
DO_FUN do_refresh_page;
DO_FUN do_pagelen;
DO_FUN do_omenu;
DO_FUN do_rmenu;
DO_FUN do_mmenu;
DO_FUN do_clear;

extern		MENU_DATA		room_page_a_data[];
extern		MENU_DATA		room_page_b_data[];
extern		MENU_DATA		room_page_c_data[];
extern		MENU_DATA		room_help_page_data[];

extern		MENU_DATA		mob_page_a_data[];
extern		MENU_DATA		mob_page_b_data[];
extern		MENU_DATA		mob_page_c_data[];
extern		MENU_DATA		mob_page_d_data[];
extern		MENU_DATA		mob_page_e_data[];
extern		MENU_DATA		mob_page_f_data[];
extern		MENU_DATA		mob_help_page_data[];

extern		MENU_DATA		obj_page_a_data[];
extern		MENU_DATA		obj_page_b_data[];
extern		MENU_DATA		obj_page_c_data[];
extern		MENU_DATA		obj_page_d_data[];
extern		MENU_DATA		obj_page_e_data[];
extern		MENU_DATA		obj_help_page_data[];

extern		MENU_DATA		control_page_a_data[];
extern		MENU_DATA		control_help_page_data[];

extern	const   char    room_page_a[];
extern	const   char    room_page_b[];
extern	const   char    room_page_c[];
extern	const   char    room_help_page[];

extern	const   char    obj_page_a[];
extern	const   char    obj_page_b[];
extern	const   char    obj_page_c[];
extern	const   char    obj_page_d[];
extern	const   char    obj_page_e[];
extern	const   char    obj_help_page[];

extern	const   char    mob_page_a[];
extern	const   char    mob_page_b[];
extern	const   char    mob_page_c[];
extern	const   char    mob_page_d[];
extern	const   char    mob_page_e[];
extern	const   char    mob_page_f[];
extern	const   char    mob_help_page[];
extern	const   char* npc_sex[3];
extern	const   char* ris_strings[];

extern	const   char    control_page_a[];
extern	const   char    control_help_page[];

#define SH_INT 1
#define INT 2
#define CHAR 3
#define STRING 4
#define SPECIAL 5


#define NO_PAGE    0
#define MOB_PAGE_A 1
#define MOB_PAGE_B 2
#define MOB_PAGE_C 3
#define MOB_PAGE_D 4
#define MOB_PAGE_E 5
#define MOB_PAGE_F 17
#define MOB_HELP_PAGE 14
#define ROOM_PAGE_A 6
#define ROOM_PAGE_B 7
#define ROOM_PAGE_C 8
#define ROOM_HELP_PAGE 15
#define OBJ_PAGE_A 9
#define OBJ_PAGE_B 10
#define OBJ_PAGE_C 11
#define OBJ_PAGE_D 12
#define OBJ_PAGE_E 13
#define OBJ_HELP_PAGE 16
#define CONTROL_PAGE_A 18
#define CONTROL_HELP_PAGE 19

#define NO_TYPE   0
#define MOB_TYPE  1
#define OBJ_TYPE  2
#define ROOM_TYPE 3
#define CONTROL_TYPE 4

#define SUB_NORTH DIR_NORTH
#define SUB_EAST  DIR_EAST
#define SUB_SOUTH DIR_SOUTH
#define SUB_WEST  DIR_WEST
#define SUB_UP    DIR_UP
#define SUB_DOWN  DIR_DOWN
#define SUB_NE    DIR_NORTHEAST
#define SUB_NW    DIR_NORTHWEST
#define SUB_SE    DIR_SOUTHEAST
#define SUB_SW    DIR_SOUTHWEST

/*
 * defines for use with this get_affect function
 */

#define RIS_000		BV00
#define RIS_R00		BV01
#define RIS_0I0		BV02
#define RIS_RI0		BV03
#define RIS_00S		BV04
#define RIS_R0S		BV05
#define RIS_0IS		BV06
#define RIS_RIS		BV07

#define GA_AFFECTED	BV09
#define GA_RESISTANT	BV10
#define GA_IMMUNE	BV11
#define GA_SUSCEPTIBLE	BV12
#define GA_RIS          BV30



/*
 *   Map Structures
 */

DO_FUN domapout;
DO_FUN do_lookmap;

struct  map_data	/* contains per-room data */
{
    long vnum;		/* which map this room belongs to */
    int x;		/* horizontal coordinate */
    int y;		/* vertical coordinate */
    char entry;		/* code that shows up on map */
};


struct  map_index_data
{
    MAP_INDEX_DATA* next;
    long 		  vnum;  		  /* vnum of the map */
    long             map_of_vnums[49][81];   /* room vnums aranged as a map */
};


MAP_INDEX_DATA* get_map_index(long vnum);
void            init_maps();


/*
 * mudprograms stuff
 */
extern	CHAR_DATA* supermob;

void oprog_speech_trigger(char* txt, CHAR_DATA* ch);
void oprog_random_trigger(OBJ_DATA* obj);
void oprog_wear_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
bool oprog_use_trigger(CHAR_DATA* ch, OBJ_DATA* obj,
                        CHAR_DATA* vict, OBJ_DATA* targ, void* vo);
void oprog_remove_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_sac_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_damage_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_repair_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_drop_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_zap_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
char* oprog_type_to_name(int type);

/*
 * MUD_PROGS START HERE
 * (object stuff)
 */
void oprog_greet_trigger(CHAR_DATA* ch);
void oprog_speech_trigger(char* txt, CHAR_DATA* ch);
void oprog_random_trigger(OBJ_DATA* obj);
void oprog_random_trigger(OBJ_DATA* obj);
void oprog_remove_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_sac_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_get_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_damage_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_repair_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_drop_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_examine_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_zap_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_pull_trigger(CHAR_DATA* ch, OBJ_DATA* obj);
void oprog_push_trigger(CHAR_DATA* ch, OBJ_DATA* obj);


/* mud prog defines */

#define ERROR_PROG        -1
#define IN_FILE_PROG       0
#define ACT_PROG           BV00
#define SPEECH_PROG        BV01
#define RAND_PROG          BV02
#define FIGHT_PROG         BV03
#define RFIGHT_PROG        BV03
#define DEATH_PROG         BV04
#define RDEATH_PROG        BV04
#define HITPRCNT_PROG      BV05
#define ENTRY_PROG         BV06
#define ENTER_PROG         BV06
#define GREET_PROG         BV07
#define RGREET_PROG	   BV07
#define OGREET_PROG        BV07
#define ALL_GREET_PROG	   BV08
#define GIVE_PROG	   BV09
#define BRIBE_PROG	   BV10
#define HOUR_PROG	   BV11
#define TIME_PROG	   BV12
#define WEAR_PROG          BV13  
#define REMOVE_PROG        BV14  
#define SAC_PROG           BV15  
#define LOOK_PROG          BV16  
#define EXA_PROG           BV17  
#define ZAP_PROG           BV18  
#define GET_PROG 	   BV19  
#define DROP_PROG	   BV20  
#define DAMAGE_PROG	   BV21  
#define REPAIR_PROG	   BV22  
#define RANDIW_PROG	   BV23  
#define SPEECHIW_PROG	   BV24  
#define PULL_PROG	   BV25  
#define PUSH_PROG	   BV26  
#define SLEEP_PROG         BV27  
#define REST_PROG          BV28  
#define LEAVE_PROG         BV29
#define SCRIPT_PROG	   BV30
#define USE_PROG           BV31

void rprog_leave_trigger(CHAR_DATA* ch);
void rprog_enter_trigger(CHAR_DATA* ch);
void rprog_sleep_trigger(CHAR_DATA* ch);
void rprog_rest_trigger(CHAR_DATA* ch);
void rprog_rfight_trigger(CHAR_DATA* ch);
void rprog_death_trigger(CHAR_DATA* killer, CHAR_DATA* ch);
void rprog_speech_trigger(char* txt, CHAR_DATA* ch);
void rprog_random_trigger(CHAR_DATA* ch);
void rprog_time_trigger(CHAR_DATA* ch);
void rprog_hour_trigger(CHAR_DATA* ch);
char* rprog_type_to_name(int type);

#define OPROG_ACT_TRIGGER
#ifdef OPROG_ACT_TRIGGER
void oprog_act_trigger(char* buf, OBJ_DATA* mobj, CHAR_DATA* ch,
            OBJ_DATA* obj, void* vo);
#endif
#define RPROG_ACT_TRIGGER
#ifdef RPROG_ACT_TRIGGER
void rprog_act_trigger(char* buf, ROOM_INDEX_DATA* room, CHAR_DATA* ch,
            OBJ_DATA* obj, void* vo);
#endif


#define send_to_char  send_to_char_color
#define send_to_pager send_to_pager_color
