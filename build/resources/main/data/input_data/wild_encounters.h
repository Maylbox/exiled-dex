//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/wild_encounters.json and Inja template src/data/wild_encounters.json.txt
//


#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 20 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 + 20
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_11 ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_TOTAL (ENCOUNTER_CHANCE_LAND_MONS_SLOT_11)
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 60 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_4 ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_WATER_MONS_TOTAL (ENCOUNTER_CHANCE_WATER_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 60 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL (ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 60 
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 70 
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1 ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 + 30
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1)
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 40 
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 + 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 + 15
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 + 4
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 + 1
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)



const struct WildPokemon gRoute101_LandMons[] =
{
    { 4, 5, SPECIES_ZIGZAGOON },
    { 4, 5, SPECIES_ROOKIDEE },
    { 4, 5, SPECIES_ZIGZAGOON },
    { 4, 5, SPECIES_ROOKIDEE },
    { 4, 5, SPECIES_NYMBLE },
    { 4, 5, SPECIES_BUDEW },
    { 4, 5, SPECIES_BUDEW },
    { 4, 5, SPECIES_BELLSPROUT },
    { 4, 5, SPECIES_PIDGEY },
    { 4, 5, SPECIES_PIDGEY },
    { 6, 8, SPECIES_EXILED_GRUBBIN },
    { 6, 8, SPECIES_EXILED_GRUBBIN },
};

const struct WildPokemonInfo gRoute101_LandMonsInfo = { 20, gRoute101_LandMons };
const struct WildPokemon gRoute102_LandMons[] =
{
    { 5, 6, SPECIES_LOTAD },
    { 5, 6, SPECIES_SEEDOT },
    { 5, 6, SPECIES_RALTS },
    { 5, 6, SPECIES_SENTRET },
    { 5, 6, SPECIES_MURKROW },
    { 5, 6, SPECIES_FLABEBE },
    { 5, 6, SPECIES_RALTS },
    { 5, 6, SPECIES_PHANPY },
    { 5, 6, SPECIES_ODDISH },
    { 5, 6, SPECIES_ESPURR },
    { 6, 8, SPECIES_EXILED_SURSKIT },
    { 6, 8, SPECIES_EXILED_SURSKIT },
};

const struct WildPokemonInfo gRoute102_LandMonsInfo = { 20, gRoute102_LandMons };
const struct WildPokemon gRoute102_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute102_WaterMonsInfo = { 4, gRoute102_WaterMons };
const struct WildPokemon gRoute102_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_POLIWAG },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_POLIWHIRL },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_POLIWHIRL },
    { 35, 40, SPECIES_POLIWHIRL },
    { 40, 45, SPECIES_POLIWHIRL },
};

const struct WildPokemonInfo gRoute102_FishingMonsInfo = { 30, gRoute102_FishingMons };
const struct WildPokemon gRoute103_LandMons[] =
{
    { 4, 5, SPECIES_WINGULL },
    { 4, 5, SPECIES_KRABBY },
    { 4, 5, SPECIES_WINGULL },
    { 4, 5, SPECIES_KRABBY },
    { 4, 5, SPECIES_TEDDIURSA },
    { 4, 5, SPECIES_SHELLOS },
    { 4, 5, SPECIES_TEDDIURSA },
    { 4, 5, SPECIES_SHELLOS },
    { 4, 5, SPECIES_BUIZEL },
    { 4, 5, SPECIES_WOOPER },
    { 6, 8, SPECIES_MUNCHLAX },
    { 6, 8, SPECIES_MUNCHLAX },
};

const struct WildPokemonInfo gRoute103_LandMonsInfo = { 20, gRoute103_LandMons };
const struct WildPokemon gRoute103_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute103_WaterMonsInfo = { 4, gRoute103_WaterMons };
const struct WildPokemon gRoute103_FishingMons[] =
{
    { 5, 10, SPECIES_TYMPOLE },
    { 5, 10, SPECIES_ARROKUDA },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute103_FishingMonsInfo = { 30, gRoute103_FishingMons };
const struct WildPokemon gRoute104_LandMons[] =
{
    { 6, 7, SPECIES_MARILL },
    { 6, 7, SPECIES_SPINARAK },
    { 6, 7, SPECIES_MARILL },
    { 6, 7, SPECIES_SPEAROW },
    { 6, 7, SPECIES_POLIWAG },
    { 6, 7, SPECIES_FOONGUS },
    { 6, 7, SPECIES_FOONGUS },
    { 6, 7, SPECIES_LEDYBA },
    { 6, 7, SPECIES_DEWPIDER },
    { 6, 7, SPECIES_BUNEARY },
    { 7, 9, SPECIES_ABRA },
    { 7, 9, SPECIES_EXILED_DODUO },
};

const struct WildPokemonInfo gRoute104_LandMonsInfo = { 20, gRoute104_LandMons };
const struct WildPokemon gRoute104_WaterMons[] =
{
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute104_WaterMonsInfo = { 4, gRoute104_WaterMons };
const struct WildPokemon gRoute104_FishingMons[] =
{
    { 5, 10, SPECIES_FEEBAS },
    { 5, 10, SPECIES_SLOWPOKE },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 20, 25, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 40, 45, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gRoute104_FishingMonsInfo = { 30, gRoute104_FishingMons };
const struct WildPokemon gRoute105_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute105_WaterMonsInfo = { 4, gRoute105_WaterMons };
const struct WildPokemon gRoute105_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute105_FishingMonsInfo = { 30, gRoute105_FishingMons };
const struct WildPokemon gRoute110_LandMons[] =
{
    { 20, 21, SPECIES_DODUO },
    { 20, 21, SPECIES_ELECTRIKE },
    { 20, 21, SPECIES_DODUO },
    { 20, 21, SPECIES_ELECTRIKE },
    { 20, 21, SPECIES_STUNKY },
    { 20, 21, SPECIES_LUXIO },
    { 20, 21, SPECIES_STUNKY },
    { 20, 21, SPECIES_YANMA },
    { 20, 21, SPECIES_MIENFOO },
    { 20, 21, SPECIES_YANMA },
    { 20, 21, SPECIES_MINUN },
    { 20, 21, SPECIES_PLUSLE },
};

const struct WildPokemonInfo gRoute110_LandMonsInfo = { 20, gRoute110_LandMons };
const struct WildPokemon gRoute110_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute110_WaterMonsInfo = { 4, gRoute110_WaterMons };
const struct WildPokemon gRoute110_FishingMons[] =
{
    { 5, 10, SPECIES_BASCULIN_WHITE_STRIPED },
    { 5, 10, SPECIES_CORSOLA },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute110_FishingMonsInfo = { 30, gRoute110_FishingMons };
const struct WildPokemon gRoute111_LandMons[] =
{
    { 43, 46, SPECIES_KROOKODILE },
    { 43, 46, SPECIES_FLYGON },
    { 43, 46, SPECIES_GIGALITH },
    { 43, 46, SPECIES_HIPPOWDON },
    { 43, 46, SPECIES_CLAYDOL },
    { 43, 46, SPECIES_CACTURNE },
    { 43, 46, SPECIES_MARACTUS },
    { 43, 46, SPECIES_DARMANITAN },
    { 43, 46, SPECIES_GABITE },
    { 43, 46, SPECIES_SANDACONDA },
    { 43, 46, SPECIES_HELIOLISK },
    { 43, 46, SPECIES_EXILED_SHARPEDO },
};

const struct WildPokemonInfo gRoute111_LandMonsInfo = { 10, gRoute111_LandMons };
const struct WildPokemon gRoute111_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute111_WaterMonsInfo = { 4, gRoute111_WaterMons };
const struct WildPokemon gRoute111_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute111_RockSmashMonsInfo = { 20, gRoute111_RockSmashMons };
const struct WildPokemon gRoute111_FishingMons[] =
{
    { 5, 10, SPECIES_MAREANIE },
    { 5, 10, SPECIES_DEWPIDER },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute111_FishingMonsInfo = { 30, gRoute111_FishingMons };
const struct WildPokemon gRoute112_LandMons[] =
{
    { 28, 32, SPECIES_NUMEL },
    { 28, 32, SPECIES_LARVITAR },
    { 28, 32, SPECIES_ROCKRUFF },
    { 28, 32, SPECIES_MISDREAVUS },
    { 28, 32, SPECIES_SANDILE },
    { 28, 32, SPECIES_DRILBUR },
    { 28, 32, SPECIES_DWEBBLE },
    { 28, 32, SPECIES_MINIOR },
    { 28, 32, SPECIES_CHARMELEON },
    { 28, 32, SPECIES_RHYHORN },
    { 28, 32, SPECIES_ABSOL },
    { 28, 32, SPECIES_EXILED_COTTONEE },
};

const struct WildPokemonInfo gRoute112_LandMonsInfo = { 20, gRoute112_LandMons };
const struct WildPokemon gRoute113_LandMons[] =
{
    { 29, 33, SPECIES_NINJASK },
    { 29, 33, SPECIES_SKORUPI },
    { 29, 33, SPECIES_TOGEDEMARU },
    { 29, 33, SPECIES_SOLOSIS },
    { 29, 33, SPECIES_TURTONATOR },
    { 29, 33, SPECIES_SLUGMA },
    { 29, 33, SPECIES_SPINDA },
    { 29, 33, SPECIES_KANGASKHAN },
    { 29, 33, SPECIES_SANDSHREW },
    { 29, 33, SPECIES_SKARMORY },
    { 29, 33, SPECIES_VIGOROTH },
    { 29, 33, SPECIES_EXILED_PACHIRISU },
};

const struct WildPokemonInfo gRoute113_LandMonsInfo = { 20, gRoute113_LandMons };
const struct WildPokemon gRoute114_LandMons[] =
{
    { 30, 33, SPECIES_DRAGONAIR },
    { 30, 33, SPECIES_FEAROW },
    { 30, 33, SPECIES_SWABLU },
    { 30, 33, SPECIES_SKUNTANK },
    { 30, 33, SPECIES_KLEFKI },
    { 30, 33, SPECIES_SALAZZLE },
    { 30, 33, SPECIES_SCYTHER },
    { 30, 33, SPECIES_LARVESTA },
    { 30, 33, SPECIES_TINKATUFF },
    { 30, 33, SPECIES_HAUNTER },
    { 30, 33, SPECIES_FRAXURE },
    { 30, 33, SPECIES_LUCARIO },
};

const struct WildPokemonInfo gRoute114_LandMonsInfo = { 20, gRoute114_LandMons };
const struct WildPokemon gRoute114_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute114_WaterMonsInfo = { 4, gRoute114_WaterMons };
const struct WildPokemon gRoute114_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute114_RockSmashMonsInfo = { 20, gRoute114_RockSmashMons };
const struct WildPokemon gRoute114_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute114_FishingMonsInfo = { 30, gRoute114_FishingMons };
const struct WildPokemon gRoute116_LandMons[] =
{
    { 8, 10, SPECIES_WOOPER_PALDEAN },
    { 8, 10, SPECIES_CROAGUNK },
    { 8, 10, SPECIES_WOOPER_PALDEAN },
    { 8, 10, SPECIES_CROAGUNK },
    { 8, 10, SPECIES_EKANS },
    { 8, 10, SPECIES_GRIMER },
    { 8, 10, SPECIES_WHISMUR },
    { 8, 10, SPECIES_WHISMUR },
    { 8, 10, SPECIES_HELIOPTILE },
    { 8, 10, SPECIES_HONEDGE },
    { 8, 10, SPECIES_NINCADA },
    { 8, 10, SPECIES_EXILED_NIDORAN_F },
};

const struct WildPokemonInfo gRoute116_LandMonsInfo = { 20, gRoute116_LandMons };
const struct WildPokemon gRoute117_LandMons[] =
{
    { 21, 24, SPECIES_PETILIL },
    { 21, 24, SPECIES_COTTONEE },
    { 21, 24, SPECIES_PETILIL },
    { 21, 24, SPECIES_COTTONEE },
    { 21, 24, SPECIES_ROSELIA },
    { 21, 24, SPECIES_DEDENNE },
    { 21, 24, SPECIES_ROSELIA },
    { 21, 24, SPECIES_DEDENNE },
    { 21, 24, SPECIES_DEERLING },
    { 21, 24, SPECIES_FALINKS },
    { 21, 24, SPECIES_DEERLING },
    { 21, 24, SPECIES_SUNFLORA },
};

const struct WildPokemonInfo gRoute117_LandMonsInfo = { 20, gRoute117_LandMons };
const struct WildPokemon gRoute117_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute117_WaterMonsInfo = { 4, gRoute117_WaterMons };
const struct WildPokemon gRoute117_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo gRoute117_FishingMonsInfo = { 30, gRoute117_FishingMons };
const struct WildPokemon gRoute118_LandMons[] =
{
    { 51, 55, SPECIES_MAUSHOLD },
    { 51, 55, SPECIES_PINSIR },
    { 51, 55, SPECIES_BRAVIARY },
    { 51, 55, SPECIES_LILLIGANT },
    { 51, 55, SPECIES_TROPIUS },
    { 5, 5, SPECIES_TOXTRICITY },
    { 5, 5, SPECIES_DODRIO },
    { 5, 5, SPECIES_EXEGGUTOR },
    { 5, 5, SPECIES_TANGROWTH },
    { 5, 5, SPECIES_SKARMORY },
    { 5, 5, SPECIES_ORICORIO },
    { 5, 5, SPECIES_EXILED_DODRIO },
};

const struct WildPokemonInfo gRoute118_LandMonsInfo = { 4, gRoute118_LandMons };
const struct WildPokemon gRoute118_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute118_WaterMonsInfo = { 4, gRoute118_WaterMons };
const struct WildPokemon gRoute118_FishingMons[] =
{
    { 5, 10, SPECIES_CHINCHOU },
    { 5, 10, SPECIES_PINCURCHIN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo gRoute118_FishingMonsInfo = { 30, gRoute118_FishingMons };
const struct WildPokemon gRoute124_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute124_WaterMonsInfo = { 4, gRoute124_WaterMons };
const struct WildPokemon gRoute124_FishingMons[] =
{
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
    { 51, 55, SPECIES_TATSUGIRI },
};

const struct WildPokemonInfo gRoute124_FishingMonsInfo = { 4, gRoute124_FishingMons };
const struct WildPokemon gPetalburgWoods_LandMons[] =
{
    { 6, 7, SPECIES_CATERPIE },
    { 6, 7, SPECIES_WEEDLE },
    { 6, 7, SPECIES_APPLIN },
    { 6, 7, SPECIES_SHROOMISH },
    { 6, 7, SPECIES_SURSKIT },
    { 6, 7, SPECIES_MORELULL },
    { 6, 7, SPECIES_JOLTIK },
    { 6, 7, SPECIES_JOLTIK },
    { 6, 7, SPECIES_SLAKOTH },
    { 6, 7, SPECIES_BOUNSWEET },
    { 6, 7, SPECIES_AIPOM },
    { 6, 7, SPECIES_EXEGGCUTE },
};

const struct WildPokemonInfo gPetalburgWoods_LandMonsInfo = { 20, gPetalburgWoods_LandMons };
const struct WildPokemon gRusturfTunnel_LandMons[] =
{
    { 9, 11, SPECIES_TRAPINCH },
    { 9, 11, SPECIES_CUBONE },
    { 9, 11, SPECIES_TRAPINCH },
    { 9, 11, SPECIES_CUBONE },
    { 9, 11, SPECIES_GEODUDE },
    { 9, 11, SPECIES_NACLI },
    { 9, 11, SPECIES_GEODUDE },
    { 9, 11, SPECIES_NACLI },
    { 9, 11, SPECIES_BRONZOR },
    { 9, 11, SPECIES_BRONZOR },
    { 9, 11, SPECIES_GLIMMET },
    { 9, 11, SPECIES_GLIMMET },
};

const struct WildPokemonInfo gRusturfTunnel_LandMonsInfo = { 10, gRusturfTunnel_LandMons };
const struct WildPokemon gGraniteCave_1F_LandMons[] =
{
    { 13, 15, SPECIES_ZUBAT },
    { 13, 15, SPECIES_ARON },
    { 13, 15, SPECIES_ZUBAT },
    { 13, 15, SPECIES_ARON },
    { 13, 15, SPECIES_GIBLE },
    { 13, 15, SPECIES_FERROSEED },
    { 13, 15, SPECIES_GIBLE },
    { 13, 15, SPECIES_FERROSEED },
    { 13, 15, SPECIES_CLEFFA },
    { 13, 15, SPECIES_CLEFFA },
    { 13, 15, SPECIES_PAWNIARD },
    { 13, 15, SPECIES_PAWNIARD },
};

const struct WildPokemonInfo gGraniteCave_1F_LandMonsInfo = { 10, gGraniteCave_1F_LandMons };
const struct WildPokemon gGraniteCave_B1F_LandMons[] =
{
    { 15, 17, SPECIES_MAWILE },
    { 15, 17, SPECIES_SABLEYE },
    { 15, 17, SPECIES_MAWILE },
    { 15, 17, SPECIES_SABLEYE },
    { 15, 17, SPECIES_DUSKULL },
    { 15, 17, SPECIES_JANGMO_O },
    { 15, 17, SPECIES_DUSKULL },
    { 15, 17, SPECIES_JANGMO_O },
    { 15, 17, SPECIES_NOIBAT },
    { 15, 17, SPECIES_NOIBAT },
    { 15, 17, SPECIES_AXEW },
    { 15, 17, SPECIES_AXEW },
};

const struct WildPokemonInfo gGraniteCave_B1F_LandMonsInfo = { 10, gGraniteCave_B1F_LandMons };
const struct WildPokemon gMtPyre_1F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_1F_LandMonsInfo = { 10, gMtPyre_1F_LandMons };
const struct WildPokemon gVictoryRoad_1F_LandMons[] =
{
    { 79, 85, SPECIES_STEELIX },
    { 79, 85, SPECIES_AEGISLASH },
    { 79, 85, SPECIES_HATTERENE },
    { 79, 85, SPECIES_GRIMMSNARL },
    { 79, 85, SPECIES_MUK },
    { 79, 85, SPECIES_ANNIHILAPE },
    { 79, 85, SPECIES_MAROWAK },
    { 79, 85, SPECIES_SALAMENCE },
    { 79, 85, SPECIES_METAGROSS },
    { 79, 85, SPECIES_SNEASLER },
    { 79, 85, SPECIES_SNEASLER },
    { 79, 85, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gVictoryRoad_1F_LandMonsInfo = { 4, gVictoryRoad_1F_LandMons };
const struct WildPokemon gSafariZone_South_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 25, 25, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo gSafariZone_South_LandMonsInfo = { 25, gSafariZone_South_LandMons };
const struct WildPokemon gUnderwater_Route126_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_EXILED_NUMEL },
};

const struct WildPokemonInfo gUnderwater_Route126_WaterMonsInfo = { 4, gUnderwater_Route126_WaterMons };
const struct WildPokemon gAbandonedShip_Rooms_B1F_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_WaterMonsInfo = { 4, gAbandonedShip_Rooms_B1F_WaterMons };
const struct WildPokemon gAbandonedShip_Rooms_B1F_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_FishingMonsInfo = { 20, gAbandonedShip_Rooms_B1F_FishingMons };
const struct WildPokemon gGraniteCave_B2F_LandMons[] =
{
    { 16, 17, SPECIES_RHYHORN },
    { 16, 17, SPECIES_ONIX },
    { 16, 17, SPECIES_ONIX },
    { 16, 17, SPECIES_RHYHORN },
    { 16, 17, SPECIES_MISDREAVUS },
    { 16, 17, SPECIES_SHIELDON },
    { 16, 17, SPECIES_CRANIDOS },
    { 16, 17, SPECIES_CRANIDOS },
    { 16, 17, SPECIES_KABUTO },
    { 16, 17, SPECIES_KABUTO },
    { 17, 18, SPECIES_EXILED_SLUGMA },
    { 17, 18, SPECIES_EXILED_SLUGMA },
};

const struct WildPokemonInfo gGraniteCave_B2F_LandMonsInfo = { 10, gGraniteCave_B2F_LandMons };
const struct WildPokemon gGraniteCave_B2F_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 10, 20, SPECIES_NOSEPASS },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gGraniteCave_B2F_RockSmashMonsInfo = { 20, gGraniteCave_B2F_RockSmashMons };
const struct WildPokemon gFieryPath_LandMons[] =
{
    { 28, 32, SPECIES_DARUMAKA },
    { 28, 32, SPECIES_SALANDIT },
    { 28, 32, SPECIES_GRIMER },
    { 28, 32, SPECIES_KOFFING },
    { 28, 32, SPECIES_CARKOL },
    { 28, 32, SPECIES_TINKATUFF },
    { 28, 32, SPECIES_GIBLE },
    { 28, 32, SPECIES_HOUNDOUR },
    { 28, 32, SPECIES_DRILBUR },
    { 28, 32, SPECIES_CENTISKORCH },
    { 28, 32, SPECIES_TYRUNT },
    { 28, 32, SPECIES_CHARMELEON },
};

const struct WildPokemonInfo gFieryPath_LandMonsInfo = { 10, gFieryPath_LandMons };
const struct WildPokemon gMeteorFalls_B1F_2R_LandMons[] =
{
    { 80, 83, SPECIES_GARCHOMP },
    { 80, 83, SPECIES_HYDREIGON },
    { 80, 83, SPECIES_METAGROSS },
    { 80, 83, SPECIES_GOODRA },
    { 80, 83, SPECIES_DRAGAPULT },
    { 80, 83, SPECIES_DRAGONITE },
    { 80, 83, SPECIES_KOMMO_O },
    { 80, 83, SPECIES_TYRANITAR },
    { 80, 83, SPECIES_BAXCALIBUR },
    { 80, 83, SPECIES_SALAMENCE },
    { 80, 83, SPECIES_EXILED_ALAKAZAM },
    { 80, 83, SPECIES_EXILED_GOLISOPOD },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_LandMonsInfo = { 10, gMeteorFalls_B1F_2R_LandMons };
const struct WildPokemon gMeteorFalls_B1F_2R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_WaterMonsInfo = { 4, gMeteorFalls_B1F_2R_WaterMons };
const struct WildPokemon gMeteorFalls_B1F_2R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_FishingMonsInfo = { 30, gMeteorFalls_B1F_2R_FishingMons };
const struct WildPokemon gJaggedPass_LandMons[] =
{
    { 31, 35, SPECIES_NUMEL },
    { 31, 35, SPECIES_GRAVELER },
    { 31, 35, SPECIES_GURDURR },
    { 31, 35, SPECIES_GLIGAR },
    { 31, 35, SPECIES_SKORUPI },
    { 31, 35, SPECIES_ARBOK },
    { 31, 35, SPECIES_NIDOQUEEN },
    { 31, 35, SPECIES_NIDOKING },
    { 31, 35, SPECIES_SANDSLASH },
    { 31, 35, SPECIES_MINIOR },
    { 31, 35, SPECIES_DODUO },
    { 31, 35, SPECIES_EXILED_NIDOQUEEN },
};

const struct WildPokemonInfo gJaggedPass_LandMonsInfo = { 20, gJaggedPass_LandMons };
const struct WildPokemon gRoute106_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute106_WaterMonsInfo = { 4, gRoute106_WaterMons };
const struct WildPokemon gRoute106_FishingMons[] =
{
    { 5, 10, SPECIES_FRILLISH },
    { 5, 10, SPECIES_POPPLIO },
    { 10, 30, SPECIES_SKRELP },
    { 10, 30, SPECIES_CLAUNCHER },
    { 10, 30, SPECIES_CLAUNCHER },
    { 25, 30, SPECIES_CLAWITZER },
    { 30, 35, SPECIES_DRAGALGE },
    { 20, 25, SPECIES_CLAWITZER },
    { 35, 40, SPECIES_DRAGALGE },
    { 40, 45, SPECIES_DRAGALGE },
};

const struct WildPokemonInfo gRoute106_FishingMonsInfo = { 30, gRoute106_FishingMons };
const struct WildPokemon gRoute107_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute107_WaterMonsInfo = { 4, gRoute107_WaterMons };
const struct WildPokemon gRoute107_FishingMons[] =
{
    { 5, 10, SPECIES_FEEBAS },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute107_FishingMonsInfo = { 30, gRoute107_FishingMons };
const struct WildPokemon gRoute108_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute108_WaterMonsInfo = { 4, gRoute108_WaterMons };
const struct WildPokemon gRoute108_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute108_FishingMonsInfo = { 30, gRoute108_FishingMons };
const struct WildPokemon gRoute109_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute109_WaterMonsInfo = { 4, gRoute109_WaterMons };
const struct WildPokemon gRoute109_FishingMons[] =
{
    { 5, 10, SPECIES_TRUBBISH },
    { 5, 10, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute109_FishingMonsInfo = { 30, gRoute109_FishingMons };
const struct WildPokemon gRoute115_LandMons[] =
{
    { 45, 48, SPECIES_GLISCOR },
    { 45, 48, SPECIES_YANMEGA },
    { 45, 48, SPECIES_ALTARIA },
    { 45, 48, SPECIES_MIENSHAO },
    { 45, 48, SPECIES_AMOONGUSS },
    { 45, 48, SPECIES_ZWEILOUS },
    { 45, 48, SPECIES_METANG },
    { 45, 48, SPECIES_SHELGON },
    { 45, 48, SPECIES_CHANSEY },
    { 45, 48, SPECIES_ZOROARK },
    { 45, 48, SPECIES_GLIMMORA },
    { 45, 48, SPECIES_DRAKLOAK },
};

const struct WildPokemonInfo gRoute115_LandMonsInfo = { 20, gRoute115_LandMons };
const struct WildPokemon gRoute115_WaterMons[] =
{
    { 51, 55, SPECIES_KINGDRA },
    { 51, 55, SPECIES_PELIPPER },
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_TOXAPEX },
    { 51, 55, SPECIES_GYARADOS },
};

const struct WildPokemonInfo gRoute115_WaterMonsInfo = { 4, gRoute115_WaterMons };
const struct WildPokemon gRoute115_FishingMons[] =
{
    { 5, 10, SPECIES_POLIWAG },
    { 5, 10, SPECIES_ARROKUDA },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute115_FishingMonsInfo = { 30, gRoute115_FishingMons };
const struct WildPokemon gNewMauville_Inside_LandMons[] =
{
    { 55, 57, SPECIES_MAGNETON },
    { 55, 57, SPECIES_MANECTRIC },
    { 55, 57, SPECIES_EELEKTROSS },
    { 55, 57, SPECIES_RAICHU },
    { 55, 57, SPECIES_TOGEDEMARU },
    { 55, 57, SPECIES_PAWMOT },
    { 55, 57, SPECIES_ELECTABUZZ },
    { 55, 57, SPECIES_JOLTEON },
    { 55, 57, SPECIES_GALVANTULA },
    { 55, 57, SPECIES_AMPHAROS },
    { 55, 57, SPECIES_DRACOZOLT },
    { 55, 57, SPECIES_EXILED_BUTTERFREE },
};

const struct WildPokemonInfo gNewMauville_Inside_LandMonsInfo = { 10, gNewMauville_Inside_LandMons };
const struct WildPokemon gRoute119_LandMons[] =
{
    { 50, 54, SPECIES_HERACROSS },
    { 50, 54, SPECIES_DOUBLADE },
    { 50, 54, SPECIES_VICTREEBEL },
    { 50, 54, SPECIES_BELLOSSOM },
    { 50, 54, SPECIES_VILEPLUME },
    { 50, 54, SPECIES_ARAQUANID },
    { 50, 54, SPECIES_EMOLGA },
    { 50, 54, SPECIES_MANDIBUZZ },
    { 50, 54, SPECIES_DRAPION },
    { 50, 54, SPECIES_ARIADOS },
    { 50, 54, SPECIES_CYCLIZAR },
    { 50, 54, SPECIES_EXILED_DODRIO },
};

const struct WildPokemonInfo gRoute119_LandMonsInfo = { 15, gRoute119_LandMons };
const struct WildPokemon gRoute119_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute119_WaterMonsInfo = { 4, gRoute119_WaterMons };
const struct WildPokemon gRoute119_FishingMons[] =
{
    { 5, 10, SPECIES_TATSUGIRI },
    { 5, 10, SPECIES_BASCULIN_WHITE_STRIPED },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 25, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo gRoute119_FishingMonsInfo = { 30, gRoute119_FishingMons };
const struct WildPokemon gRoute120_LandMons[] =
{
    { 51, 54, SPECIES_SHIFTRY },
    { 51, 54, SPECIES_EXEGGUTOR },
    { 51, 54, SPECIES_TANGROWTH },
    { 51, 54, SPECIES_TOXICROAK },
    { 51, 54, SPECIES_AMOONGUSS },
    { 51, 54, SPECIES_TROPIUS },
    { 51, 54, SPECIES_YANMEGA },
    { 51, 54, SPECIES_GALVANTULA },
    { 51, 54, SPECIES_ABSOL },
    { 51, 54, SPECIES_ABSOL },
    { 51, 54, SPECIES_LOKIX },
    { 51, 54, SPECIES_EXILED_VIKAVOLT },
};

const struct WildPokemonInfo gRoute120_LandMonsInfo = { 20, gRoute120_LandMons };
const struct WildPokemon gRoute120_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute120_WaterMonsInfo = { 4, gRoute120_WaterMons };
const struct WildPokemon gRoute120_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gRoute120_FishingMonsInfo = { 30, gRoute120_FishingMons };
const struct WildPokemon gRoute121_LandMons[] =
{
    { 52, 55, SPECIES_ESPATHRA },
    { 52, 55, SPECIES_BANETTE },
    { 52, 55, SPECIES_DUSCLOPS },
    { 52, 55, SPECIES_SIGILYPH },
    { 52, 55, SPECIES_MIGHTYENA },
    { 52, 55, SPECIES_CORVIKNIGHT },
    { 52, 55, SPECIES_FLAPPLE },
    { 52, 55, SPECIES_APPLETUN },
    { 52, 55, SPECIES_WHIMSICOTT },
    { 52, 55, SPECIES_LILLIGANT },
    { 52, 55, SPECIES_ROSERADE },
    { 52, 55, SPECIES_EXEGGUTOR },
};

const struct WildPokemonInfo gRoute121_LandMonsInfo = { 20, gRoute121_LandMons };
const struct WildPokemon gRoute121_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute121_WaterMonsInfo = { 4, gRoute121_WaterMons };
const struct WildPokemon gRoute121_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute121_FishingMonsInfo = { 30, gRoute121_FishingMons };
const struct WildPokemon gRoute122_WaterMons[] =
{
    { 51, 55, SPECIES_STARMIE },
    { 51, 55, SPECIES_KINGDRA },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute122_WaterMonsInfo = { 4, gRoute122_WaterMons };
const struct WildPokemon gRoute122_FishingMons[] =
{
    { 5, 10, SPECIES_CORSOLA_GALARIAN },
    { 5, 10, SPECIES_CORSOLA_GALARIAN },
    { 10, 30, SPECIES_CORSOLA_GALARIAN },
    { 10, 30, SPECIES_CORSOLA_GALARIAN },
    { 10, 30, SPECIES_CORSOLA_GALARIAN },
    { 30, 35, SPECIES_CORSOLA_GALARIAN },
    { 30, 35, SPECIES_CORSOLA_GALARIAN },
    { 25, 30, SPECIES_CORSOLA_GALARIAN },
    { 35, 40, SPECIES_CORSOLA_GALARIAN },
    { 40, 45, SPECIES_CORSOLA_GALARIAN },
};

const struct WildPokemonInfo gRoute122_FishingMonsInfo = { 30, gRoute122_FishingMons };
const struct WildPokemon gRoute123_LandMons[] =
{
    { 52, 55, SPECIES_PELIPPER },
    { 52, 55, SPECIES_SCOLIPEDE },
    { 52, 55, SPECIES_MAROWAK },
    { 52, 55, SPECIES_SCYTHER },
    { 52, 55, SPECIES_MIGHTYENA },
    { 52, 55, SPECIES_POLTEAGEIST },
    { 52, 55, SPECIES_LOKIX },
    { 52, 55, SPECIES_CERULEDGE },
    { 52, 55, SPECIES_ARMAROUGE },
    { 52, 55, SPECIES_PANGORO },
    { 52, 55, SPECIES_STUNFISK },
    { 52, 55, SPECIES_CINCCINO },
};

const struct WildPokemonInfo gRoute123_LandMonsInfo = { 20, gRoute123_LandMons };
const struct WildPokemon gRoute123_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute123_WaterMonsInfo = { 4, gRoute123_WaterMons };
const struct WildPokemon gRoute123_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute123_FishingMonsInfo = { 30, gRoute123_FishingMons };
const struct WildPokemon gMtPyre_2F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_2F_LandMonsInfo = { 10, gMtPyre_2F_LandMons };
const struct WildPokemon gMtPyre_3F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_3F_LandMonsInfo = { 10, gMtPyre_3F_LandMons };
const struct WildPokemon gMtPyre_4F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_4F_LandMonsInfo = { 10, gMtPyre_4F_LandMons };
const struct WildPokemon gMtPyre_5F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_5F_LandMonsInfo = { 10, gMtPyre_5F_LandMons };
const struct WildPokemon gMtPyre_6F_LandMons[] =
{
    { 51, 56, SPECIES_GENGAR },
    { 51, 56, SPECIES_SABLEYE },
    { 51, 56, SPECIES_BANETTE },
    { 51, 56, SPECIES_DUSCLOPS },
    { 51, 56, SPECIES_ROTOM },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_MISMAGIUS },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_MIMIKYU },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_MASQUERAIN },
};

const struct WildPokemonInfo gMtPyre_6F_LandMonsInfo = { 10, gMtPyre_6F_LandMons };
const struct WildPokemon gMtPyre_Exterior_LandMons[] =
{
    { 51, 56, SPECIES_BRONZONG },
    { 51, 56, SPECIES_DRIFBLIM },
    { 51, 56, SPECIES_PARASECT },
    { 51, 56, SPECIES_PARASECT },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_NINETALES },
    { 51, 56, SPECIES_NINETALES },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_DODRIO },
};

const struct WildPokemonInfo gMtPyre_Exterior_LandMonsInfo = { 10, gMtPyre_Exterior_LandMons };
const struct WildPokemon gMtPyre_Summit_LandMons[] =
{
    { 51, 56, SPECIES_BRONZONG },
    { 51, 56, SPECIES_DRIFBLIM },
    { 51, 56, SPECIES_PARASECT },
    { 51, 56, SPECIES_PARASECT },
    { 51, 56, SPECIES_CERULEDGE },
    { 51, 56, SPECIES_NINETALES },
    { 51, 56, SPECIES_NINETALES },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_DRAKLOAK },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_ZOROARK },
    { 51, 56, SPECIES_EXILED_DODRIO },
};

const struct WildPokemonInfo gMtPyre_Summit_LandMonsInfo = { 10, gMtPyre_Summit_LandMons };
const struct WildPokemon gGraniteCave_StevensRoom_LandMons[] =
{
    { 15, 15, SPECIES_ARON },
    { 15, 15, SPECIES_ARON },
    { 15, 15, SPECIES_ANORITH },
    { 15, 15, SPECIES_ANORITH },
    { 15, 15, SPECIES_LILEEP },
    { 15, 15, SPECIES_LILEEP },
    { 15, 15, SPECIES_BALTOY },
    { 15, 15, SPECIES_BALTOY },
    { 15, 15, SPECIES_BELDUM },
    { 15, 15, SPECIES_BELDUM },
    { 15, 15, SPECIES_SKARMORY },
    { 51, 51, SPECIES_SKARMORY },
};

const struct WildPokemonInfo gGraniteCave_StevensRoom_LandMonsInfo = { 10, gGraniteCave_StevensRoom_LandMons };
const struct WildPokemon gRoute125_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute125_WaterMonsInfo = { 4, gRoute125_WaterMons };
const struct WildPokemon gRoute125_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute125_FishingMonsInfo = { 30, gRoute125_FishingMons };
const struct WildPokemon gRoute126_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute126_WaterMonsInfo = { 4, gRoute126_WaterMons };
const struct WildPokemon gRoute126_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute126_FishingMonsInfo = { 30, gRoute126_FishingMons };
const struct WildPokemon gRoute127_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute127_WaterMonsInfo = { 4, gRoute127_WaterMons };
const struct WildPokemon gRoute127_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute127_FishingMonsInfo = { 30, gRoute127_FishingMons };
const struct WildPokemon gRoute128_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute128_WaterMonsInfo = { 4, gRoute128_WaterMons };
const struct WildPokemon gRoute128_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute128_FishingMonsInfo = { 30, gRoute128_FishingMons };
const struct WildPokemon gRoute129_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute129_WaterMonsInfo = { 4, gRoute129_WaterMons };
const struct WildPokemon gRoute129_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute129_FishingMonsInfo = { 30, gRoute129_FishingMons };
const struct WildPokemon gRoute130_LandMons[] =
{
    { 30, 30, SPECIES_WYNAUT },
    { 35, 35, SPECIES_WYNAUT },
    { 25, 25, SPECIES_WYNAUT },
    { 40, 40, SPECIES_WYNAUT },
    { 20, 20, SPECIES_WYNAUT },
    { 45, 45, SPECIES_WYNAUT },
    { 15, 15, SPECIES_WYNAUT },
    { 50, 50, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
};

const struct WildPokemonInfo gRoute130_LandMonsInfo = { 20, gRoute130_LandMons };
const struct WildPokemon gRoute130_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute130_WaterMonsInfo = { 4, gRoute130_WaterMons };
const struct WildPokemon gRoute130_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute130_FishingMonsInfo = { 30, gRoute130_FishingMons };
const struct WildPokemon gRoute131_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute131_WaterMonsInfo = { 4, gRoute131_WaterMons };
const struct WildPokemon gRoute131_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute131_FishingMonsInfo = { 30, gRoute131_FishingMons };
const struct WildPokemon gRoute132_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute132_WaterMonsInfo = { 4, gRoute132_WaterMons };
const struct WildPokemon gRoute132_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute132_FishingMonsInfo = { 30, gRoute132_FishingMons };
const struct WildPokemon gRoute133_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute133_WaterMonsInfo = { 4, gRoute133_WaterMons };
const struct WildPokemon gRoute133_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute133_FishingMonsInfo = { 30, gRoute133_FishingMons };
const struct WildPokemon gRoute134_WaterMons[] =
{
    { 51, 55, SPECIES_PALAFIN },
    { 51, 55, SPECIES_JELLICENT },
    { 51, 55, SPECIES_GYARADOS },
    { 51, 55, SPECIES_DONDOZO },
    { 51, 55, SPECIES_TOXAPEX },
};

const struct WildPokemonInfo gRoute134_WaterMonsInfo = { 4, gRoute134_WaterMons };
const struct WildPokemon gRoute134_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gRoute134_FishingMonsInfo = { 30, gRoute134_FishingMons };
const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo = { 4, gAbandonedShip_HiddenFloorCorridors_WaterMons };
const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo = { 20, gAbandonedShip_HiddenFloorCorridors_FishingMons };
const struct WildPokemon gSeafloorCavern_Room1_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room1_LandMonsInfo = { 4, gSeafloorCavern_Room1_LandMons };
const struct WildPokemon gSeafloorCavern_Room2_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room2_LandMonsInfo = { 4, gSeafloorCavern_Room2_LandMons };
const struct WildPokemon gSeafloorCavern_Room3_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room3_LandMonsInfo = { 4, gSeafloorCavern_Room3_LandMons };
const struct WildPokemon gSeafloorCavern_Room4_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room4_LandMonsInfo = { 4, gSeafloorCavern_Room4_LandMons };
const struct WildPokemon gSeafloorCavern_Room5_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room5_LandMonsInfo = { 4, gSeafloorCavern_Room5_LandMons };
const struct WildPokemon gSeafloorCavern_Room6_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_LandMonsInfo = { 4, gSeafloorCavern_Room6_LandMons };
const struct WildPokemon gSeafloorCavern_Room6_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_WaterMonsInfo = { 4, gSeafloorCavern_Room6_WaterMons };
const struct WildPokemon gSeafloorCavern_Room6_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Room6_FishingMonsInfo = { 10, gSeafloorCavern_Room6_FishingMons };
const struct WildPokemon gSeafloorCavern_Room7_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_LandMonsInfo = { 4, gSeafloorCavern_Room7_LandMons };
const struct WildPokemon gSeafloorCavern_Room7_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_WaterMonsInfo = { 4, gSeafloorCavern_Room7_WaterMons };
const struct WildPokemon gSeafloorCavern_Room7_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Room7_FishingMonsInfo = { 10, gSeafloorCavern_Room7_FishingMons };
const struct WildPokemon gSeafloorCavern_Room8_LandMons[] =
{
    { 72, 75, SPECIES_SEISMITOAD },
    { 72, 75, SPECIES_GOLISOPOD },
    { 72, 75, SPECIES_KABUTOPS },
    { 72, 75, SPECIES_OMASTAR },
    { 72, 75, SPECIES_CROBAT },
    { 72, 75, SPECIES_FERALIGATR },
    { 72, 75, SPECIES_TOXAPEX },
    { 72, 75, SPECIES_BAXCALIBUR },
    { 72, 75, SPECIES_CRYOGONAL },
    { 72, 75, SPECIES_FROSMOTH },
    { 72, 75, SPECIES_FROSLASS },
    { 72, 75, SPECIES_EXILED_WHISCASH },
};

const struct WildPokemonInfo gSeafloorCavern_Room8_LandMonsInfo = { 4, gSeafloorCavern_Room8_LandMons };
const struct WildPokemon gSeafloorCavern_Entrance_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_WaterMonsInfo = { 0, gSeafloorCavern_Entrance_WaterMons };
const struct WildPokemon gSeafloorCavern_Entrance_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_FishingMonsInfo = { 10, gSeafloorCavern_Entrance_FishingMons };
const struct WildPokemon gCaveOfOrigin_Entrance_LandMons[] =
{
    { 75, 77, SPECIES_NOIVERN },
    { 75, 77, SPECIES_CROBAT },
    { 75, 77, SPECIES_HATTERENE },
    { 75, 77, SPECIES_GRIMMSNARL },
    { 75, 77, SPECIES_MAWILE },
    { 75, 77, SPECIES_BISHARP },
    { 75, 77, SPECIES_SABLEYE },
    { 75, 77, SPECIES_GHOLDENGO },
    { 75, 77, SPECIES_GIGALITH },
    { 75, 77, SPECIES_GARGANACL },
    { 75, 77, SPECIES_AURORUS },
    { 75, 77, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gCaveOfOrigin_Entrance_LandMonsInfo = { 4, gCaveOfOrigin_Entrance_LandMons };
const struct WildPokemon gCaveOfOrigin_1F_LandMons[] =
{
    { 75, 77, SPECIES_NOIVERN },
    { 75, 77, SPECIES_CROBAT },
    { 75, 77, SPECIES_HATTERENE },
    { 75, 77, SPECIES_GRIMMSNARL },
    { 75, 77, SPECIES_MAWILE },
    { 75, 77, SPECIES_BISHARP },
    { 75, 77, SPECIES_SABLEYE },
    { 75, 77, SPECIES_GHOLDENGO },
    { 75, 77, SPECIES_GIGALITH },
    { 75, 77, SPECIES_GARGANACL },
    { 75, 77, SPECIES_AURORUS },
    { 75, 77, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gCaveOfOrigin_1F_LandMonsInfo = { 4, gCaveOfOrigin_1F_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap1_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap1_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap2_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap2_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap3_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap3_LandMons };
const struct WildPokemon gNewMauville_Entrance_LandMons[] =
{
    { 55, 57, SPECIES_MAGNETON },
    { 55, 57, SPECIES_MANECTRIC },
    { 55, 57, SPECIES_EELEKTROSS },
    { 55, 57, SPECIES_RAICHU },
    { 55, 57, SPECIES_TOGEDEMARU },
    { 55, 57, SPECIES_PAWMOT },
    { 55, 57, SPECIES_ELECTABUZZ },
    { 55, 57, SPECIES_JOLTEON },
    { 55, 57, SPECIES_GALVANTULA },
    { 55, 57, SPECIES_AMPHAROS },
    { 55, 57, SPECIES_PORYGON },
    { 55, 57, SPECIES_EXILED_BUTTERFREE },
};

const struct WildPokemonInfo gNewMauville_Entrance_LandMonsInfo = { 10, gNewMauville_Entrance_LandMons };
const struct WildPokemon gSafariZone_Southwest_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 27, 27, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo gSafariZone_Southwest_LandMonsInfo = { 25, gSafariZone_Southwest_LandMons };
const struct WildPokemon gSafariZone_Southwest_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gSafariZone_Southwest_WaterMonsInfo = { 9, gSafariZone_Southwest_WaterMons };
const struct WildPokemon gSafariZone_Southwest_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo gSafariZone_Southwest_FishingMonsInfo = { 35, gSafariZone_Southwest_FishingMons };
const struct WildPokemon gSafariZone_North_LandMons[] =
{
    { 27, 27, SPECIES_PHANPY },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_PHANPY },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_NATU },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_NATU },
    { 29, 29, SPECIES_XATU },
    { 27, 27, SPECIES_HERACROSS },
    { 31, 31, SPECIES_XATU },
    { 29, 29, SPECIES_HERACROSS },
};

const struct WildPokemonInfo gSafariZone_North_LandMonsInfo = { 25, gSafariZone_North_LandMons };
const struct WildPokemon gSafariZone_North_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 20, 25, SPECIES_GEODUDE },
    { 25, 30, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gSafariZone_North_RockSmashMonsInfo = { 25, gSafariZone_North_RockSmashMons };
const struct WildPokemon gSafariZone_Northwest_LandMons[] =
{
    { 27, 27, SPECIES_RHYHORN },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_RHYHORN },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_DODUO },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_DODUO },
    { 29, 29, SPECIES_DODRIO },
    { 27, 27, SPECIES_PINSIR },
    { 31, 31, SPECIES_DODRIO },
    { 29, 29, SPECIES_PINSIR },
};

const struct WildPokemonInfo gSafariZone_Northwest_LandMonsInfo = { 25, gSafariZone_Northwest_LandMons };
const struct WildPokemon gSafariZone_Northwest_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_GOLDUCK },
    { 25, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo gSafariZone_Northwest_WaterMonsInfo = { 9, gSafariZone_Northwest_WaterMons };
const struct WildPokemon gSafariZone_Northwest_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo gSafariZone_Northwest_FishingMonsInfo = { 35, gSafariZone_Northwest_FishingMons };
const struct WildPokemon gVictoryRoad_B1F_LandMons[] =
{
    { 79, 85, SPECIES_GARCHOMP },
    { 79, 85, SPECIES_TYRANITAR },
    { 79, 85, SPECIES_MEDICHAM },
    { 79, 85, SPECIES_MACHAMP },
    { 79, 85, SPECIES_LUCARIO },
    { 79, 85, SPECIES_ANNIHILAPE },
    { 79, 85, SPECIES_MAROWAK },
    { 79, 85, SPECIES_DRAGAPULT },
    { 79, 85, SPECIES_BAXCALIBUR },
    { 79, 85, SPECIES_GARGANACL },
    { 79, 85, SPECIES_GARGANACL },
    { 79, 85, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gVictoryRoad_B1F_LandMonsInfo = { 4, gVictoryRoad_B1F_LandMons };
const struct WildPokemon gVictoryRoad_B1F_RockSmashMons[] =
{
    { 30, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gVictoryRoad_B1F_RockSmashMonsInfo = { 20, gVictoryRoad_B1F_RockSmashMons };
const struct WildPokemon gVictoryRoad_B2F_LandMons[] =
{
    { 79, 85, SPECIES_DRAGONITE },
    { 79, 85, SPECIES_AERODACTYL },
    { 79, 85, SPECIES_SCIZOR },
    { 79, 85, SPECIES_STEELIX },
    { 79, 85, SPECIES_KROOKODILE },
    { 79, 85, SPECIES_ANNIHILAPE },
    { 79, 85, SPECIES_SCRAFTY },
    { 79, 85, SPECIES_TINKATON },
    { 79, 85, SPECIES_MELMETAL },
    { 79, 85, SPECIES_GARGANACL },
    { 79, 85, SPECIES_GARGANACL },
    { 79, 85, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gVictoryRoad_B2F_LandMonsInfo = { 4, gVictoryRoad_B2F_LandMons };
const struct WildPokemon gVictoryRoad_B2F_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 25, 30, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gVictoryRoad_B2F_WaterMonsInfo = { 4, gVictoryRoad_B2F_WaterMons };
const struct WildPokemon gVictoryRoad_B2F_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gVictoryRoad_B2F_FishingMonsInfo = { 30, gVictoryRoad_B2F_FishingMons };
const struct WildPokemon gMeteorFalls_1F_1R_LandMons[] =
{
    { 30, 34, SPECIES_GRAVELER },
    { 30, 34, SPECIES_LAIRON },
    { 30, 34, SPECIES_DEINO },
    { 30, 34, SPECIES_DREEPY },
    { 30, 34, SPECIES_GOLBAT },
    { 30, 34, SPECIES_FERROSEED },
    { 30, 34, SPECIES_BOLDORE },
    { 30, 34, SPECIES_METANG },
    { 30, 34, SPECIES_GABITE },
    { 30, 34, SPECIES_HATTREM },
    { 30, 34, SPECIES_MORGREM },
    { 30, 34, SPECIES_DURALUDON },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_LandMonsInfo = { 10, gMeteorFalls_1F_1R_LandMons };
const struct WildPokemon gMeteorFalls_1F_1R_WaterMons[] =
{
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_WaterMonsInfo = { 4, gMeteorFalls_1F_1R_WaterMons };
const struct WildPokemon gMeteorFalls_1F_1R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_FishingMonsInfo = { 30, gMeteorFalls_1F_1R_FishingMons };
const struct WildPokemon gMeteorFalls_1F_2R_LandMons[] =
{
    { 80, 83, SPECIES_GARCHOMP },
    { 80, 83, SPECIES_HYDREIGON },
    { 80, 83, SPECIES_METAGROSS },
    { 80, 83, SPECIES_GOODRA },
    { 80, 83, SPECIES_DRAGAPULT },
    { 80, 83, SPECIES_DRAGONITE },
    { 80, 83, SPECIES_KOMMO_O },
    { 80, 83, SPECIES_TYRANITAR },
    { 80, 83, SPECIES_BAXCALIBUR },
    { 80, 83, SPECIES_SALAMENCE },
    { 80, 83, SPECIES_EXILED_ALAKAZAM },
    { 80, 83, SPECIES_EXILED_GOLISOPOD },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_LandMonsInfo = { 10, gMeteorFalls_1F_2R_LandMons };
const struct WildPokemon gMeteorFalls_1F_2R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_WaterMonsInfo = { 4, gMeteorFalls_1F_2R_WaterMons };
const struct WildPokemon gMeteorFalls_1F_2R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_FishingMonsInfo = { 30, gMeteorFalls_1F_2R_FishingMons };
const struct WildPokemon gMeteorFalls_B1F_1R_LandMons[] =
{
    { 80, 83, SPECIES_GARCHOMP },
    { 80, 83, SPECIES_HYDREIGON },
    { 80, 83, SPECIES_METAGROSS },
    { 80, 83, SPECIES_GOODRA },
    { 80, 83, SPECIES_DRAGAPULT },
    { 80, 83, SPECIES_DRAGONITE },
    { 80, 83, SPECIES_KOMMO_O },
    { 80, 83, SPECIES_TYRANITAR },
    { 80, 83, SPECIES_BAXCALIBUR },
    { 80, 83, SPECIES_SALAMENCE },
    { 80, 83, SPECIES_EXILED_ALAKAZAM },
    { 80, 83, SPECIES_EXILED_GOLISOPOD },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_LandMonsInfo = { 10, gMeteorFalls_B1F_1R_LandMons };
const struct WildPokemon gMeteorFalls_B1F_1R_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_WaterMonsInfo = { 4, gMeteorFalls_B1F_1R_WaterMons };
const struct WildPokemon gMeteorFalls_B1F_1R_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_FishingMonsInfo = { 30, gMeteorFalls_B1F_1R_FishingMons };
const struct WildPokemon gShoalCave_LowTideStairsRoom_LandMons[] =
{
    { 68, 71, SPECIES_CRYOGONAL },
    { 68, 71, SPECIES_WEAVILE },
    { 68, 71, SPECIES_FROSMOTH },
    { 68, 71, SPECIES_FROSLASS },
    { 68, 71, SPECIES_GLALIE },
    { 68, 71, SPECIES_ABOMASNOW },
    { 68, 71, SPECIES_MAMOSWINE },
    { 68, 71, SPECIES_ARCTOZOLT },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_EXILED_WALREIN },
    { 68, 71, SPECIES_EXILED_ALAKAZAM },
};

const struct WildPokemonInfo gShoalCave_LowTideStairsRoom_LandMonsInfo = { 4, gShoalCave_LowTideStairsRoom_LandMons };
const struct WildPokemon gShoalCave_LowTideLowerRoom_LandMons[] =
{
    { 68, 71, SPECIES_CRYOGONAL },
    { 68, 71, SPECIES_WEAVILE },
    { 68, 71, SPECIES_FROSMOTH },
    { 68, 71, SPECIES_FROSLASS },
    { 68, 71, SPECIES_GLALIE },
    { 68, 71, SPECIES_ABOMASNOW },
    { 68, 71, SPECIES_MAMOSWINE },
    { 68, 71, SPECIES_ARCTOZOLT },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_EXILED_WALREIN },
    { 68, 71, SPECIES_EXILED_ALAKAZAM },
};

const struct WildPokemonInfo gShoalCave_LowTideLowerRoom_LandMonsInfo = { 4, gShoalCave_LowTideLowerRoom_LandMons };
const struct WildPokemon gShoalCave_LowTideInnerRoom_LandMons[] =
{
    { 68, 71, SPECIES_CRYOGONAL },
    { 68, 71, SPECIES_WEAVILE },
    { 68, 71, SPECIES_FROSMOTH },
    { 68, 71, SPECIES_FROSLASS },
    { 68, 71, SPECIES_GLALIE },
    { 68, 71, SPECIES_ABOMASNOW },
    { 68, 71, SPECIES_MAMOSWINE },
    { 68, 71, SPECIES_ARCTOZOLT },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_EXILED_WALREIN },
    { 68, 71, SPECIES_EXILED_ALAKAZAM },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_LandMonsInfo = { 4, gShoalCave_LowTideInnerRoom_LandMons };
const struct WildPokemon gShoalCave_LowTideInnerRoom_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_WaterMonsInfo = { 4, gShoalCave_LowTideInnerRoom_WaterMons };
const struct WildPokemon gShoalCave_LowTideInnerRoom_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_FishingMonsInfo = { 10, gShoalCave_LowTideInnerRoom_FishingMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoom_LandMons[] =
{
    { 68, 71, SPECIES_CRYOGONAL },
    { 68, 71, SPECIES_WEAVILE },
    { 68, 71, SPECIES_FROSMOTH },
    { 68, 71, SPECIES_FROSLASS },
    { 68, 71, SPECIES_GLALIE },
    { 68, 71, SPECIES_ABOMASNOW },
    { 68, 71, SPECIES_MAMOSWINE },
    { 68, 71, SPECIES_ARCTOZOLT },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_EXILED_WALREIN },
    { 68, 71, SPECIES_EXILED_ALAKAZAM },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_LandMonsInfo = { 4, gShoalCave_LowTideEntranceRoom_LandMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoom_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_WaterMonsInfo = { 4, gShoalCave_LowTideEntranceRoom_WaterMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoom_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_FishingMonsInfo = { 10, gShoalCave_LowTideEntranceRoom_FishingMons };
const struct WildPokemon gLilycoveCity_LandMons[] =
{
    { 53, 55, SPECIES_RAICHU_ALOLAN },
    { 53, 55, SPECIES_SEISMITOAD },
    { 53, 55, SPECIES_GARBODOR },
    { 53, 55, SPECIES_RIBOMBEE },
    { 53, 55, SPECIES_ARBOK },
    { 53, 55, SPECIES_HATTERENE },
    { 53, 55, SPECIES_PALOSSAND },
    { 53, 55, SPECIES_AUDINO },
    { 53, 55, SPECIES_SAWK },
    { 53, 55, SPECIES_THROH },
    { 53, 55, SPECIES_TOXICROAK },
    { 53, 55, SPECIES_GASTRODON },
};

const struct WildPokemonInfo gLilycoveCity_LandMonsInfo = { 10, gLilycoveCity_LandMons };
const struct WildPokemon gLilycoveCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gLilycoveCity_WaterMonsInfo = { 4, gLilycoveCity_WaterMons };
const struct WildPokemon gLilycoveCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_FINNEON },
    { 10, 30, SPECIES_FINNEON },
    { 10, 30, SPECIES_STARYU },
    { 10, 30, SPECIES_BRUXISH },
    { 25, 30, SPECIES_LUMINEON },
    { 30, 35, SPECIES_BRUXISH },
    { 25, 30, SPECIES_STARMIE },
    { 35, 40, SPECIES_STARMIE },
    { 40, 45, SPECIES_STARMIE },
};

const struct WildPokemonInfo gLilycoveCity_FishingMonsInfo = { 10, gLilycoveCity_FishingMons };
const struct WildPokemon gDewfordTown_LandMons[] =
{
    { 10, 12, SPECIES_MACHOP },
    { 10, 12, SPECIES_MANKEY },
    { 10, 12, SPECIES_SCRAGGY },
    { 10, 12, SPECIES_MIENFOO },
    { 10, 12, SPECIES_RIOLU },
    { 10, 12, SPECIES_TIMBURR },
    { 10, 12, SPECIES_MAKUHITA },
    { 10, 12, SPECIES_SANDYGAST },
    { 10, 12, SPECIES_CHARCADET },
    { 10, 12, SPECIES_CHARCADET },
    { 10, 12, SPECIES_HAWLUCHA },
    { 10, 12, SPECIES_HAWLUCHA },
};

const struct WildPokemonInfo gDewfordTown_LandMonsInfo = { 10, gDewfordTown_LandMons };
const struct WildPokemon gDewfordTown_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gDewfordTown_WaterMonsInfo = { 4, gDewfordTown_WaterMons };
const struct WildPokemon gDewfordTown_FishingMons[] =
{
    { 5, 10, SPECIES_SQUIRTLE },
    { 5, 10, SPECIES_STARYU },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_SHELLDER },
    { 25, 30, SPECIES_FINNEON },
    { 30, 35, SPECIES_SHELLDER },
    { 20, 25, SPECIES_LUMINEON },
    { 35, 40, SPECIES_STARMIE },
    { 40, 45, SPECIES_CLOYSTER },
};

const struct WildPokemonInfo gDewfordTown_FishingMonsInfo = { 10, gDewfordTown_FishingMons };
const struct WildPokemon gSlateportCity_LandMons[] =
{
    { 19, 20, SPECIES_TRUBBISH },
    { 19, 20, SPECIES_KIRLIA },
    { 19, 20, SPECIES_KIRLIA },
    { 19, 20, SPECIES_TRUBBISH },
    { 19, 20, SPECIES_GLIGAR },
    { 19, 20, SPECIES_GOOMY },
    { 19, 20, SPECIES_GLIGAR },
    { 19, 20, SPECIES_GOOMY },
    { 19, 20, SPECIES_ELECTRIKE },
    { 19, 20, SPECIES_ELECTRIKE },
    { 19, 20, SPECIES_EXILED_CATERPIE },
    { 19, 20, SPECIES_EXILED_CATERPIE },
};

const struct WildPokemonInfo gSlateportCity_LandMonsInfo = { 10, gSlateportCity_LandMons };
const struct WildPokemon gSlateportCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gSlateportCity_WaterMonsInfo = { 4, gSlateportCity_WaterMons };
const struct WildPokemon gSlateportCity_FishingMons[] =
{
    { 5, 10, SPECIES_HORSEA },
    { 5, 10, SPECIES_FRILLISH },
    { 10, 30, SPECIES_HORSEA },
    { 10, 30, SPECIES_FRILLISH },
    { 10, 30, SPECIES_ALOMOMOLA },
    { 25, 30, SPECIES_SEADRA },
    { 30, 35, SPECIES_ALOMOMOLA },
    { 20, 25, SPECIES_JELLICENT },
    { 35, 40, SPECIES_KINGDRA },
    { 40, 45, SPECIES_KINGDRA },
};

const struct WildPokemonInfo gSlateportCity_FishingMonsInfo = { 10, gSlateportCity_FishingMons };
const struct WildPokemon gMossdeepCity_LandMons[] =
{
    { 67, 69, SPECIES_CLEFABLE },
    { 67, 69, SPECIES_SIGILYPH },
    { 67, 69, SPECIES_HATTERENE },
    { 67, 69, SPECIES_GRIMMSNARL },
    { 67, 69, SPECIES_MEDICHAM },
    { 67, 69, SPECIES_TOGEKISS },
    { 67, 69, SPECIES_BRONZONG },
    { 67, 69, SPECIES_ESPEON },
    { 67, 69, SPECIES_SYLVEON },
    { 67, 69, SPECIES_ESPATHRA },
    { 67, 69, SPECIES_INDEEDEE },
    { 67, 69, SPECIES_ARMAROUGE },
};

const struct WildPokemonInfo gMossdeepCity_LandMonsInfo = { 10, gMossdeepCity_LandMons };
const struct WildPokemon gMossdeepCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gMossdeepCity_WaterMonsInfo = { 4, gMossdeepCity_WaterMons };
const struct WildPokemon gMossdeepCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gMossdeepCity_FishingMonsInfo = { 10, gMossdeepCity_FishingMons };
const struct WildPokemon gPacifidlogTown_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gPacifidlogTown_WaterMonsInfo = { 4, gPacifidlogTown_WaterMons };
const struct WildPokemon gPacifidlogTown_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gPacifidlogTown_FishingMonsInfo = { 10, gPacifidlogTown_FishingMons };
const struct WildPokemon gEverGrandeCity_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gEverGrandeCity_WaterMonsInfo = { 4, gEverGrandeCity_WaterMons };
const struct WildPokemon gEverGrandeCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo gEverGrandeCity_FishingMonsInfo = { 10, gEverGrandeCity_FishingMons };
const struct WildPokemon gPetalburgCity_WaterMons[] =
{
    { 40, 45, SPECIES_MARILL },
    { 40, 45, SPECIES_AZUMARILL },
    { 40, 45, SPECIES_MASQUERAIN },
    { 40, 45, SPECIES_MASQUERAIN },
    { 40, 45, SPECIES_MASQUERAIN },
};

const struct WildPokemonInfo gPetalburgCity_WaterMonsInfo = { 1, gPetalburgCity_WaterMons };
const struct WildPokemon gPetalburgCity_FishingMons[] =
{
    { 5, 10, SPECIES_MUDKIP },
    { 5, 10, SPECIES_CORPHISH },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CRAWDAUNT },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo gPetalburgCity_FishingMonsInfo = { 10, gPetalburgCity_FishingMons };
const struct WildPokemon gUnderwater_Route124_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_EXILED_NUMEL },
};

const struct WildPokemonInfo gUnderwater_Route124_WaterMonsInfo = { 4, gUnderwater_Route124_WaterMons };
const struct WildPokemon gShoalCave_LowTideIceRoom_LandMons[] =
{
    { 68, 71, SPECIES_CRYOGONAL },
    { 68, 71, SPECIES_WEAVILE },
    { 68, 71, SPECIES_FROSMOTH },
    { 68, 71, SPECIES_FROSLASS },
    { 68, 71, SPECIES_GLALIE },
    { 68, 71, SPECIES_ABOMASNOW },
    { 68, 71, SPECIES_MAMOSWINE },
    { 68, 71, SPECIES_ARCTOZOLT },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_BAXCALIBUR },
    { 68, 71, SPECIES_EXILED_WALREIN },
    { 68, 71, SPECIES_EXILED_ALAKAZAM },
};

const struct WildPokemonInfo gShoalCave_LowTideIceRoom_LandMonsInfo = { 4, gShoalCave_LowTideIceRoom_LandMons };
const struct WildPokemon gSkyPillar_1F_LandMons[] =
{
    { 75, 76, SPECIES_GOLURK },
    { 75, 76, SPECIES_BRONZONG },
    { 75, 76, SPECIES_ALAKAZAM },
    { 75, 76, SPECIES_SABLEYE },
    { 75, 76, SPECIES_CLAYDOL },
    { 75, 76, SPECIES_BANETTE },
    { 75, 76, SPECIES_HATTERENE },
    { 75, 76, SPECIES_HYDREIGON },
    { 75, 76, SPECIES_SALAMENCE },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gSkyPillar_1F_LandMonsInfo = { 10, gSkyPillar_1F_LandMons };
const struct WildPokemon gSootopolisCity_LandMons[] =
{
    { 75, 77, SPECIES_TOXAPEX },
    { 75, 77, SPECIES_SLOWBRO },
    { 75, 77, SPECIES_BLASTOISE },
    { 75, 77, SPECIES_FERALIGATR },
    { 75, 77, SPECIES_SWAMPERT },
    { 75, 77, SPECIES_EMPOLEON },
    { 75, 77, SPECIES_SAMUROTT },
    { 75, 77, SPECIES_GRENINJA },
    { 75, 77, SPECIES_PRIMARINA },
    { 75, 77, SPECIES_INTELEON },
    { 75, 77, SPECIES_QUAQUAVAL },
    { 75, 77, SPECIES_EXILED_WALREIN },
};

const struct WildPokemonInfo gSootopolisCity_LandMonsInfo = { 10, gSootopolisCity_LandMons };
const struct WildPokemon gSootopolisCity_WaterMons[] =
{
    { 5, 35, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gSootopolisCity_WaterMonsInfo = { 1, gSootopolisCity_WaterMons };
const struct WildPokemon gSootopolisCity_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_GYARADOS },
    { 35, 45, SPECIES_GYARADOS },
    { 5, 45, SPECIES_GYARADOS },
};

const struct WildPokemonInfo gSootopolisCity_FishingMonsInfo = { 10, gSootopolisCity_FishingMons };
const struct WildPokemon gSkyPillar_3F_LandMons[] =
{
    { 75, 76, SPECIES_GOLURK },
    { 75, 76, SPECIES_BRONZONG },
    { 75, 76, SPECIES_ALAKAZAM },
    { 75, 76, SPECIES_SABLEYE },
    { 75, 76, SPECIES_CLAYDOL },
    { 75, 76, SPECIES_BANETTE },
    { 75, 76, SPECIES_HATTERENE },
    { 75, 76, SPECIES_HYDREIGON },
    { 75, 76, SPECIES_SALAMENCE },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gSkyPillar_3F_LandMonsInfo = { 10, gSkyPillar_3F_LandMons };
const struct WildPokemon gSkyPillar_5F_LandMons[] =
{
    { 75, 76, SPECIES_GOLURK },
    { 75, 76, SPECIES_BRONZONG },
    { 75, 76, SPECIES_ALAKAZAM },
    { 75, 76, SPECIES_SABLEYE },
    { 75, 76, SPECIES_CLAYDOL },
    { 75, 76, SPECIES_BANETTE },
    { 75, 76, SPECIES_HATTERENE },
    { 75, 76, SPECIES_HYDREIGON },
    { 75, 76, SPECIES_SALAMENCE },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_ALTARIA },
    { 75, 76, SPECIES_EXILED_DRUDDIGON },
};

const struct WildPokemonInfo gSkyPillar_5F_LandMonsInfo = { 10, gSkyPillar_5F_LandMons };
const struct WildPokemon gSafariZone_Southeast_LandMons[] =
{
    { 33, 33, SPECIES_SUNKERN },
    { 34, 34, SPECIES_MAREEP },
    { 35, 35, SPECIES_SUNKERN },
    { 36, 36, SPECIES_MAREEP },
    { 34, 34, SPECIES_AIPOM },
    { 33, 33, SPECIES_SPINARAK },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_SNUBBULL },
    { 36, 36, SPECIES_STANTLER },
    { 37, 37, SPECIES_GLIGAR },
    { 39, 39, SPECIES_STANTLER },
    { 40, 40, SPECIES_GLIGAR },
};

const struct WildPokemonInfo gSafariZone_Southeast_LandMonsInfo = { 25, gSafariZone_Southeast_LandMons };
const struct WildPokemon gSafariZone_Southeast_WaterMons[] =
{
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gSafariZone_Southeast_WaterMonsInfo = { 9, gSafariZone_Southeast_WaterMons };
const struct WildPokemon gSafariZone_Southeast_FishingMons[] =
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_REMORAID },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 35, 40, SPECIES_OCTILLERY },
};

const struct WildPokemonInfo gSafariZone_Southeast_FishingMonsInfo = { 35, gSafariZone_Southeast_FishingMons };
const struct WildPokemon gSafariZone_Northeast_LandMons[] =
{
    { 33, 33, SPECIES_AIPOM },
    { 34, 34, SPECIES_TEDDIURSA },
    { 35, 35, SPECIES_AIPOM },
    { 36, 36, SPECIES_TEDDIURSA },
    { 34, 34, SPECIES_SUNKERN },
    { 33, 33, SPECIES_LEDYBA },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_PINECO },
    { 36, 36, SPECIES_HOUNDOUR },
    { 37, 37, SPECIES_MILTANK },
    { 39, 39, SPECIES_HOUNDOUR },
    { 40, 40, SPECIES_MILTANK },
};

const struct WildPokemonInfo gSafariZone_Northeast_LandMonsInfo = { 25, gSafariZone_Northeast_LandMons };
const struct WildPokemon gSafariZone_Northeast_RockSmashMons[] =
{
    { 25, 30, SPECIES_SHUCKLE },
    { 20, 25, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 35, 40, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gSafariZone_Northeast_RockSmashMonsInfo = { 25, gSafariZone_Northeast_RockSmashMons };
const struct WildPokemon gMagmaHideout_1F_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_1F_LandMonsInfo = { 10, gMagmaHideout_1F_LandMons };
const struct WildPokemon gMagmaHideout_2F_1R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_2F_1R_LandMonsInfo = { 10, gMagmaHideout_2F_1R_LandMons };
const struct WildPokemon gMagmaHideout_2F_2R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_2F_2R_LandMonsInfo = { 10, gMagmaHideout_2F_2R_LandMons };
const struct WildPokemon gMagmaHideout_3F_1R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_3F_1R_LandMonsInfo = { 10, gMagmaHideout_3F_1R_LandMons };
const struct WildPokemon gMagmaHideout_3F_2R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_3F_2R_LandMonsInfo = { 10, gMagmaHideout_3F_2R_LandMons };
const struct WildPokemon gMagmaHideout_4F_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_4F_LandMonsInfo = { 10, gMagmaHideout_4F_LandMons };
const struct WildPokemon gMagmaHideout_3F_3R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_3F_3R_LandMonsInfo = { 10, gMagmaHideout_3F_3R_LandMons };
const struct WildPokemon gMagmaHideout_2F_3R_LandMons[] =
{
    { 57, 59, SPECIES_GOLEM },
    { 57, 59, SPECIES_TORKOAL },
    { 57, 59, SPECIES_STEELIX },
    { 57, 59, SPECIES_MAWILE },
    { 57, 59, SPECIES_GARCHOMP },
    { 57, 59, SPECIES_EXCADRILL },
    { 57, 59, SPECIES_GARGANACL },
    { 57, 59, SPECIES_SNEASLER },
    { 57, 59, SPECIES_ORTHWORM },
    { 57, 59, SPECIES_MAGCARGO },
    { 57, 59, SPECIES_TYRANTRUM },
    { 57, 59, SPECIES_DRACOVISH },
};

const struct WildPokemonInfo gMagmaHideout_2F_3R_LandMonsInfo = { 10, gMagmaHideout_2F_3R_LandMons };
const struct WildPokemon gMirageTower_1F_LandMons[] =
{
    { 43, 45, SPECIES_OMASTAR },
    { 43, 45, SPECIES_KABUTOPS },
    { 43, 45, SPECIES_AERODACTYL },
    { 43, 45, SPECIES_ARMALDO },
    { 43, 45, SPECIES_CRADILY },
    { 43, 45, SPECIES_BASTIODON },
    { 43, 45, SPECIES_RAMPARDOS },
    { 43, 45, SPECIES_CARRACOSTA },
    { 43, 45, SPECIES_ARCHEOPS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_AURORUS },
};

const struct WildPokemonInfo gMirageTower_1F_LandMonsInfo = { 10, gMirageTower_1F_LandMons };
const struct WildPokemon gMirageTower_2F_LandMons[] =
{
    { 43, 45, SPECIES_BASTIODON },
    { 43, 45, SPECIES_RAMPARDOS },
    { 43, 45, SPECIES_CARRACOSTA },
    { 43, 45, SPECIES_ARCHEOPS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_DRACOVISH },
    { 43, 45, SPECIES_DRACOZOLT },
    { 43, 45, SPECIES_ARCTOVISH },
    { 43, 45, SPECIES_ARCTOZOLT },
};

const struct WildPokemonInfo gMirageTower_2F_LandMonsInfo = { 10, gMirageTower_2F_LandMons };
const struct WildPokemon gMirageTower_3F_LandMons[] =
{
    { 43, 45, SPECIES_BASTIODON },
    { 43, 45, SPECIES_RAMPARDOS },
    { 43, 45, SPECIES_CARRACOSTA },
    { 43, 45, SPECIES_ARCHEOPS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_DRACOVISH },
    { 43, 45, SPECIES_DRACOZOLT },
    { 43, 45, SPECIES_ARCTOVISH },
    { 43, 45, SPECIES_ARCTOZOLT },
};

const struct WildPokemonInfo gMirageTower_3F_LandMonsInfo = { 10, gMirageTower_3F_LandMons };
const struct WildPokemon gMirageTower_4F_LandMons[] =
{
    { 43, 45, SPECIES_BASTIODON },
    { 43, 45, SPECIES_RAMPARDOS },
    { 43, 45, SPECIES_CARRACOSTA },
    { 43, 45, SPECIES_ARCHEOPS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_TYRANTRUM },
    { 43, 45, SPECIES_AURORUS },
    { 43, 45, SPECIES_DRACOVISH },
    { 43, 45, SPECIES_DRACOZOLT },
    { 43, 45, SPECIES_ARCTOVISH },
    { 43, 45, SPECIES_ARCTOZOLT },
};

const struct WildPokemonInfo gMirageTower_4F_LandMonsInfo = { 10, gMirageTower_4F_LandMons };
const struct WildPokemon gDesertUnderpass_LandMons[] =
{
    { 38, 38, SPECIES_DITTO },
    { 35, 35, SPECIES_WHISMUR },
    { 40, 40, SPECIES_DITTO },
    { 40, 40, SPECIES_LOUDRED },
    { 41, 41, SPECIES_DITTO },
    { 36, 36, SPECIES_WHISMUR },
    { 38, 38, SPECIES_LOUDRED },
    { 42, 42, SPECIES_DITTO },
    { 38, 38, SPECIES_WHISMUR },
    { 43, 43, SPECIES_DITTO },
    { 44, 44, SPECIES_LOUDRED },
    { 45, 45, SPECIES_DITTO },
};

const struct WildPokemonInfo gDesertUnderpass_LandMonsInfo = { 10, gDesertUnderpass_LandMons };
const struct WildPokemon gArtisanCave_B1F_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gArtisanCave_B1F_LandMonsInfo = { 10, gArtisanCave_B1F_LandMons };
const struct WildPokemon gArtisanCave_1F_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gArtisanCave_1F_LandMonsInfo = { 10, gArtisanCave_1F_LandMons };
const struct WildPokemon gAlteringCave1_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo gAlteringCave1_LandMonsInfo = { 7, gAlteringCave1_LandMons };
const struct WildPokemon gAlteringCave2_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo gAlteringCave2_LandMonsInfo = { 7, gAlteringCave2_LandMons };
const struct WildPokemon gAlteringCave3_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo gAlteringCave3_LandMonsInfo = { 7, gAlteringCave3_LandMons };
const struct WildPokemon gAlteringCave4_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo gAlteringCave4_LandMonsInfo = { 7, gAlteringCave4_LandMons };
const struct WildPokemon gAlteringCave5_LandMons[] =
{
    { 10, 10, SPECIES_TEDDIURSA },
    { 12, 12, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
    { 10, 10, SPECIES_TEDDIURSA },
    { 12, 12, SPECIES_TEDDIURSA },
    { 16, 16, SPECIES_TEDDIURSA },
    { 6, 6, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo gAlteringCave5_LandMonsInfo = { 7, gAlteringCave5_LandMons };
const struct WildPokemon gAlteringCave6_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo gAlteringCave6_LandMonsInfo = { 7, gAlteringCave6_LandMons };
const struct WildPokemon gAlteringCave7_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gAlteringCave7_LandMonsInfo = { 7, gAlteringCave7_LandMons };
const struct WildPokemon gAlteringCave8_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo gAlteringCave8_LandMonsInfo = { 7, gAlteringCave8_LandMons };
const struct WildPokemon gAlteringCave9_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gAlteringCave9_LandMonsInfo = { 7, gAlteringCave9_LandMons };
const struct WildPokemon gMeteorFalls_StevensCave_LandMons[] =
{
    { 33, 33, SPECIES_LITWICK },
    { 35, 35, SPECIES_LITWICK },
    { 33, 33, SPECIES_LITWICK },
    { 35, 35, SPECIES_LITWICK },
    { 33, 33, SPECIES_LITWICK },
    { 37, 37, SPECIES_LITWICK },
    { 35, 35, SPECIES_LITWICK },
    { 39, 39, SPECIES_LITWICK },
    { 38, 38, SPECIES_LITWICK },
    { 40, 40, SPECIES_LITWICK },
    { 38, 38, SPECIES_LITWICK },
    { 40, 40, SPECIES_LITWICK },
};

const struct WildPokemonInfo gMeteorFalls_StevensCave_LandMonsInfo = { 10, gMeteorFalls_StevensCave_LandMons };
const struct WildPokemon gScorchedSlab0_LandMons[] =
{
    { 51, 54, SPECIES_CERULEDGE },
    { 51, 54, SPECIES_CENTISKORCH },
    { 51, 54, SPECIES_ARMAROUGE },
    { 51, 54, SPECIES_CHARIZARD },
    { 51, 54, SPECIES_TYPHLOSION },
    { 51, 54, SPECIES_BLAZIKEN },
    { 51, 54, SPECIES_INFERNAPE },
    { 51, 54, SPECIES_EMBOAR },
    { 51, 54, SPECIES_DELPHOX },
    { 51, 54, SPECIES_INCINEROAR },
    { 51, 54, SPECIES_CINDERACE },
    { 51, 54, SPECIES_SKELEDIRGE },
};

const struct WildPokemonInfo gScorchedSlab0_LandMonsInfo = { 20, gScorchedSlab0_LandMons };
const struct WildPokemon gMauvilleCity0_LandMons[] =
{
    { 22, 24, SPECIES_MAGNEMITE },
    { 22, 24, SPECIES_HELIOPTILE },
    { 22, 24, SPECIES_MAGNEMITE },
    { 22, 24, SPECIES_TOGEDEMARU },
    { 22, 24, SPECIES_FLAAFFY },
    { 22, 24, SPECIES_STUNFISK },
    { 22, 24, SPECIES_CHARJABUG },
    { 22, 24, SPECIES_CHARJABUG },
    { 22, 24, SPECIES_HELIOPTILE },
    { 22, 24, SPECIES_PIKACHU },
    { 22, 24, SPECIES_ELECTABUZZ },
    { 22, 24, SPECIES_EXILED_METAPOD },
};

const struct WildPokemonInfo gMauvilleCity0_LandMonsInfo = { 10, gMauvilleCity0_LandMons };
const struct WildPokemon gRustboroCity0_LandMons[] =
{
    { 8, 10, SPECIES_TINKATINK },
    { 8, 10, SPECIES_TOGEPI },
    { 8, 10, SPECIES_TINKATINK },
    { 8, 10, SPECIES_TOGEPI },
    { 8, 10, SPECIES_PARAS },
    { 8, 10, SPECIES_WURMPLE },
    { 8, 10, SPECIES_PARAS },
    { 8, 10, SPECIES_WURMPLE },
    { 8, 10, SPECIES_SHUPPET },
    { 8, 10, SPECIES_SHUPPET },
    { 8, 10, SPECIES_RIOLU },
    { 8, 10, SPECIES_RIOLU },
};

const struct WildPokemonInfo gRustboroCity0_LandMonsInfo = { 10, gRustboroCity0_LandMons };
const struct WildPokemon gFortreeCity0_LandMons[] =
{
    { 50, 53, SPECIES_SWELLOW },
    { 50, 53, SPECIES_CORVIKNIGHT },
    { 50, 53, SPECIES_STARAPTOR },
    { 50, 53, SPECIES_FEAROW },
    { 50, 53, SPECIES_PIDGEOT },
    { 50, 53, SPECIES_DODRIO },
    { 50, 53, SPECIES_BRAVIARY },
    { 50, 53, SPECIES_MANDIBUZZ },
    { 50, 53, SPECIES_BUTTERFREE },
    { 50, 53, SPECIES_BEEDRILL },
    { 50, 53, SPECIES_VIKAVOLT },
    { 50, 53, SPECIES_EXILED_VIKAVOLT },
};

const struct WildPokemonInfo gFortreeCity0_LandMonsInfo = { 10, gFortreeCity0_LandMons };
const struct WildPokemon gOldaleTown0_LandMons[] =
{
    { 4, 5, SPECIES_MEOWTH },
    { 4, 5, SPECIES_POOCHYENA },
    { 4, 5, SPECIES_MEOWTH },
    { 4, 5, SPECIES_POOCHYENA },
    { 4, 5, SPECIES_TAILLOW },
    { 4, 5, SPECIES_STARLY },
    { 4, 5, SPECIES_MAREEP },
    { 4, 5, SPECIES_HATENNA },
    { 4, 5, SPECIES_VENIPEDE },
    { 4, 5, SPECIES_HATENNA },
    { 6, 8, SPECIES_VENIPEDE },
    { 6, 8, SPECIES_EEVEE },
};

const struct WildPokemonInfo gOldaleTown0_LandMonsInfo = { 20, gOldaleTown0_LandMons };
const struct WildPokemon gLavaridgeTown0_LandMons[] =
{
    { 30, 34, SPECIES_CENTISKORCH },
    { 30, 34, SPECIES_MAGMAR },
    { 30, 34, SPECIES_LAMPENT },
    { 30, 34, SPECIES_TURTONATOR },
    { 30, 34, SPECIES_CHARMELEON },
    { 30, 34, SPECIES_QUILAVA },
    { 30, 34, SPECIES_COMBUSKEN },
    { 30, 34, SPECIES_MONFERNO },
    { 30, 34, SPECIES_PIGNITE },
    { 30, 34, SPECIES_TORRACAT },
    { 30, 34, SPECIES_RABOOT },
    { 30, 34, SPECIES_CROCALOR },
};

const struct WildPokemonInfo gLavaridgeTown0_LandMonsInfo = { 10, gLavaridgeTown0_LandMons };
const struct WildPokemon gFallarborTown0_LandMons[] =
{
    { 29, 33, SPECIES_INDEEDEE },
    { 29, 33, SPECIES_SILICOBRA },
    { 29, 33, SPECIES_MUDBRAY },
    { 29, 33, SPECIES_MORGREM },
    { 29, 33, SPECIES_HATTREM },
    { 29, 33, SPECIES_HIPPOPOTAS },
    { 29, 33, SPECIES_SINISTEA },
    { 29, 33, SPECIES_GRAVELER },
    { 29, 33, SPECIES_NIDORINA },
    { 29, 33, SPECIES_NIDORINO },
    { 29, 33, SPECIES_RHYHORN },
    { 29, 33, SPECIES_EXILED_NIDORINA },
};

const struct WildPokemonInfo gFallarborTown0_LandMonsInfo = { 10, gFallarborTown0_LandMons };
const struct WildPokemon gVerdanturfTown0_LandMons[] =
{
    { 21, 25, SPECIES_LOMBRE },
    { 21, 25, SPECIES_PINCURCHIN },
    { 21, 25, SPECIES_KIRLIA },
    { 21, 25, SPECIES_DEWPIDER },
    { 21, 25, SPECIES_WARTORTLE },
    { 21, 25, SPECIES_CROCONAW },
    { 21, 25, SPECIES_MARSHTOMP },
    { 21, 25, SPECIES_PRINPLUP },
    { 21, 25, SPECIES_DEWOTT },
    { 21, 25, SPECIES_BRIONNE },
    { 21, 25, SPECIES_DRIZZILE },
    { 21, 25, SPECIES_QUAXWELL },
};

const struct WildPokemonInfo gVerdanturfTown0_LandMonsInfo = { 10, gVerdanturfTown0_LandMons };
const struct WildPokemon gVerdanturfTown0_FishingMons[] =
{
    { 1, 5, SPECIES_DONDOZO },
    { 1, 5, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 40, SPECIES_DONDOZO },
    { 1, 50, SPECIES_DONDOZO },
    { 1, 100, SPECIES_DONDOZO },
};

const struct WildPokemonInfo gVerdanturfTown0_FishingMonsInfo = { 30, gVerdanturfTown0_FishingMons };
const struct WildPokemon gDeepWoods0_LandMons[] =
{
    { 8, 10, SPECIES_BULBASAUR },
    { 8, 10, SPECIES_CHIKORITA },
    { 8, 10, SPECIES_TREECKO },
    { 8, 10, SPECIES_TURTWIG },
    { 8, 10, SPECIES_SNIVY },
    { 8, 10, SPECIES_CHESPIN },
    { 8, 10, SPECIES_ROWLET },
    { 8, 10, SPECIES_GROOKEY },
    { 8, 10, SPECIES_SPRIGATITO },
    { 8, 10, SPECIES_FOMANTIS },
    { 8, 10, SPECIES_TANGELA },
    { 8, 10, SPECIES_EXILED_MACHOP },
};

const struct WildPokemonInfo gDeepWoods0_LandMonsInfo = { 10, gDeepWoods0_LandMons };

const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .landMonsInfo = &gRoute101_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
        .landMonsInfo = &gRoute102_LandMonsInfo,
        .waterMonsInfo = &gRoute102_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute102_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
        .landMonsInfo = &gRoute103_LandMonsInfo,
        .waterMonsInfo = &gRoute103_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute103_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
        .landMonsInfo = &gRoute104_LandMonsInfo,
        .waterMonsInfo = &gRoute104_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute104_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute105_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute105_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
        .landMonsInfo = &gRoute110_LandMonsInfo,
        .waterMonsInfo = &gRoute110_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute110_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
        .landMonsInfo = &gRoute111_LandMonsInfo,
        .waterMonsInfo = &gRoute111_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute111_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute111_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
        .landMonsInfo = &gRoute112_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
        .landMonsInfo = &gRoute113_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
        .landMonsInfo = &gRoute114_LandMonsInfo,
        .waterMonsInfo = &gRoute114_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute114_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute114_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
        .landMonsInfo = &gRoute116_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
        .landMonsInfo = &gRoute117_LandMonsInfo,
        .waterMonsInfo = &gRoute117_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute117_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
        .landMonsInfo = &gRoute118_LandMonsInfo,
        .waterMonsInfo = &gRoute118_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute118_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute124_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute124_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
        .landMonsInfo = &gPetalburgWoods_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
        .landMonsInfo = &gRusturfTunnel_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
        .landMonsInfo = &gGraniteCave_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
        .landMonsInfo = &gGraniteCave_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
        .landMonsInfo = &gMtPyre_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo = &gVictoryRoad_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTH),
        .landMonsInfo = &gSafariZone_South_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE126),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater_Route126_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_Rooms_B1F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_Rooms_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
        .landMonsInfo = &gGraniteCave_B2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gGraniteCave_B2F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
        .landMonsInfo = &gFieryPath_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
        .landMonsInfo = &gMeteorFalls_B1F_2R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
        .landMonsInfo = &gJaggedPass_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute106_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute106_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute107_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute107_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute108_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute108_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute109_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute109_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
        .landMonsInfo = &gRoute115_LandMonsInfo,
        .waterMonsInfo = &gRoute115_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute115_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
        .landMonsInfo = &gNewMauville_Inside_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
        .landMonsInfo = &gRoute119_LandMonsInfo,
        .waterMonsInfo = &gRoute119_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute119_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
        .landMonsInfo = &gRoute120_LandMonsInfo,
        .waterMonsInfo = &gRoute120_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute120_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
        .landMonsInfo = &gRoute121_LandMonsInfo,
        .waterMonsInfo = &gRoute121_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute121_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute122_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute122_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
        .landMonsInfo = &gRoute123_LandMonsInfo,
        .waterMonsInfo = &gRoute123_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute123_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
        .landMonsInfo = &gMtPyre_2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
        .landMonsInfo = &gMtPyre_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
        .landMonsInfo = &gMtPyre_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
        .landMonsInfo = &gMtPyre_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
        .landMonsInfo = &gMtPyre_6F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
        .landMonsInfo = &gMtPyre_Exterior_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
        .landMonsInfo = &gMtPyre_Summit_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
        .landMonsInfo = &gGraniteCave_StevensRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute125_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute125_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute126_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute126_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute127_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute127_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute128_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute128_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute129_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute129_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
        .landMonsInfo = &gRoute130_LandMonsInfo,
        .waterMonsInfo = &gRoute130_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute130_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute131_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute131_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute132_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute132_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute133_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute133_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute134_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute134_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
        .landMonsInfo = &gSeafloorCavern_Room1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
        .landMonsInfo = &gSeafloorCavern_Room2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
        .landMonsInfo = &gSeafloorCavern_Room3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
        .landMonsInfo = &gSeafloorCavern_Room4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
        .landMonsInfo = &gSeafloorCavern_Room5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
        .landMonsInfo = &gSeafloorCavern_Room6_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room6_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room6_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
        .landMonsInfo = &gSeafloorCavern_Room7_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room7_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room7_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
        .landMonsInfo = &gSeafloorCavern_Room8_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSeafloorCavern_Entrance_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Entrance_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
        .landMonsInfo = &gCaveOfOrigin_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
        .landMonsInfo = &gCaveOfOrigin_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
        .landMonsInfo = &gNewMauville_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
        .landMonsInfo = &gSafariZone_Southwest_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Southwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Southwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
        .landMonsInfo = &gSafariZone_North_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_North_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
        .landMonsInfo = &gSafariZone_Northwest_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Northwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Northwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
        .landMonsInfo = &gVictoryRoad_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gVictoryRoad_B1F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
        .landMonsInfo = &gVictoryRoad_B2F_LandMonsInfo,
        .waterMonsInfo = &gVictoryRoad_B2F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gVictoryRoad_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
        .landMonsInfo = &gMeteorFalls_1F_1R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
        .landMonsInfo = &gMeteorFalls_1F_2R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
        .landMonsInfo = &gMeteorFalls_B1F_1R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .landMonsInfo = &gShoalCave_LowTideStairsRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideLowerRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideInnerRoom_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideInnerRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideInnerRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideEntranceRoom_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideEntranceRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideEntranceRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
        .landMonsInfo = &gLilycoveCity_LandMonsInfo,
        .waterMonsInfo = &gLilycoveCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gLilycoveCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
        .landMonsInfo = &gDewfordTown_LandMonsInfo,
        .waterMonsInfo = &gDewfordTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gDewfordTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
        .landMonsInfo = &gSlateportCity_LandMonsInfo,
        .waterMonsInfo = &gSlateportCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSlateportCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
        .landMonsInfo = &gMossdeepCity_LandMonsInfo,
        .waterMonsInfo = &gMossdeepCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMossdeepCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPacifidlogTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPacifidlogTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gEverGrandeCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gEverGrandeCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPetalburgCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPetalburgCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE124),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater_Route124_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideIceRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
        .landMonsInfo = &gSkyPillar_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
        .landMonsInfo = &gSootopolisCity_LandMonsInfo,
        .waterMonsInfo = &gSootopolisCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSootopolisCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
        .landMonsInfo = &gSkyPillar_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
        .landMonsInfo = &gSkyPillar_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
        .landMonsInfo = &gSafariZone_Southeast_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Southeast_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Southeast_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
        .landMonsInfo = &gSafariZone_Northeast_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_Northeast_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_1F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_1F),
        .landMonsInfo = &gMagmaHideout_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_1R),
        .landMonsInfo = &gMagmaHideout_2F_1R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_2R),
        .landMonsInfo = &gMagmaHideout_2F_2R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_1R),
        .landMonsInfo = &gMagmaHideout_3F_1R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_2R),
        .landMonsInfo = &gMagmaHideout_3F_2R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_4F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_4F),
        .landMonsInfo = &gMagmaHideout_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_3R),
        .landMonsInfo = &gMagmaHideout_3F_3R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_3R),
        .landMonsInfo = &gMagmaHideout_2F_3R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_1F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_1F),
        .landMonsInfo = &gMirageTower_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_2F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_2F),
        .landMonsInfo = &gMirageTower_2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_3F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_3F),
        .landMonsInfo = &gMirageTower_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_4F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_4F),
        .landMonsInfo = &gMirageTower_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DESERT_UNDERPASS),
        .mapNum = MAP_NUM(DESERT_UNDERPASS),
        .landMonsInfo = &gDesertUnderpass_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_B1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_B1F),
        .landMonsInfo = &gArtisanCave_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_1F),
        .landMonsInfo = &gArtisanCave_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave6_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave7_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave8_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave9_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_STEVENS_CAVE),
        .mapNum = MAP_NUM(METEOR_FALLS_STEVENS_CAVE),
        .landMonsInfo = &gMeteorFalls_StevensCave_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SCORCHED_SLAB),
        .mapNum = MAP_NUM(SCORCHED_SLAB),
        .landMonsInfo = &gScorchedSlab0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAUVILLE_CITY),
        .mapNum = MAP_NUM(MAUVILLE_CITY),
        .landMonsInfo = &gMauvilleCity0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUSTBORO_CITY),
        .mapNum = MAP_NUM(RUSTBORO_CITY),
        .landMonsInfo = &gRustboroCity0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FORTREE_CITY),
        .mapNum = MAP_NUM(FORTREE_CITY),
        .landMonsInfo = &gFortreeCity0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(OLDALE_TOWN),
        .mapNum = MAP_NUM(OLDALE_TOWN),
        .landMonsInfo = &gOldaleTown0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(LAVARIDGE_TOWN),
        .mapNum = MAP_NUM(LAVARIDGE_TOWN),
        .landMonsInfo = &gLavaridgeTown0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FALLARBOR_TOWN),
        .mapNum = MAP_NUM(FALLARBOR_TOWN),
        .landMonsInfo = &gFallarborTown0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VERDANTURF_TOWN),
        .mapNum = MAP_NUM(VERDANTURF_TOWN),
        .landMonsInfo = &gVerdanturfTown0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gVerdanturfTown0_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DEEP_WOODS),
        .mapNum = MAP_NUM(DEEP_WOODS),
        .landMonsInfo = &gDeepWoods0_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};



const struct WildPokemon gBattlePyramid_1_LandMons[] =
{
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
};

const struct WildPokemonInfo gBattlePyramid_1_LandMonsInfo = { 4, gBattlePyramid_1_LandMons };
const struct WildPokemon gBattlePyramid_2_LandMons[] =
{
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMANDER },
};

const struct WildPokemonInfo gBattlePyramid_2_LandMonsInfo = { 4, gBattlePyramid_2_LandMons };
const struct WildPokemon gBattlePyramid_3_LandMons[] =
{
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
};

const struct WildPokemonInfo gBattlePyramid_3_LandMonsInfo = { 4, gBattlePyramid_3_LandMons };
const struct WildPokemon gBattlePyramid_4_LandMons[] =
{
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
};

const struct WildPokemonInfo gBattlePyramid_4_LandMonsInfo = { 4, gBattlePyramid_4_LandMons };
const struct WildPokemon gBattlePyramid_5_LandMons[] =
{
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
};

const struct WildPokemonInfo gBattlePyramid_5_LandMonsInfo = { 4, gBattlePyramid_5_LandMons };
const struct WildPokemon gBattlePyramid_6_LandMons[] =
{
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
};

const struct WildPokemonInfo gBattlePyramid_6_LandMonsInfo = { 4, gBattlePyramid_6_LandMons };
const struct WildPokemon gBattlePyramid_7_LandMons[] =
{
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
};

const struct WildPokemonInfo gBattlePyramid_7_LandMonsInfo = { 8, gBattlePyramid_7_LandMons };

const struct WildPokemonHeader gBattlePyramidWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePyramid_1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePyramid_2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePyramid_3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePyramid_4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 5,
        .landMonsInfo = &gBattlePyramid_5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 6,
        .landMonsInfo = &gBattlePyramid_6_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 7,
        .landMonsInfo = &gBattlePyramid_7_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};



const struct WildPokemon gBattlePike_1_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_1_LandMonsInfo = { 10, gBattlePike_1_LandMons };
const struct WildPokemon gBattlePike_2_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_2_LandMonsInfo = { 10, gBattlePike_2_LandMons };
const struct WildPokemon gBattlePike_3_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_3_LandMonsInfo = { 10, gBattlePike_3_LandMons };
const struct WildPokemon gBattlePike_4_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_4_LandMonsInfo = { 10, gBattlePike_4_LandMons };

const struct WildPokemonHeader gBattlePikeWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePike_1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePike_2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePike_3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePike_4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};
