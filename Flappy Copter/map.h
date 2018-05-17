#include <SFML/Graphics.hpp>
#include <iostream>

const int HEIGHT_MAP = 10;
const int WIDTH_MAP = 200;
sf::String TileMap[HEIGHT_MAP] = {
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

sf::String Cloud[HEIGHT_MAP] = {
	"                                                                                                                                                                                                      ",
	"     s       s                   s                                                                                                                      s                               s    s    s   ",
	"                          s             s       s                 s                  s                 s                    s                  s                 s                                    ",
	"                                                        s                 s                                                                                               s                           ",
	"       s       s                  s                                 s          s            s         s           s                      s                                                 s         s",
	"                          s                s           s                              s                                                                                                               ",
	"                                                                         s                            s                                                                                               ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
};
sf::String Bird[20] = {
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

sf::String Tree[5] = {
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"                                                                                                                                                                                                      ",
	"     t       t         t          t      t        t           t            t         t        t         t            t       t          t         t             t           t           t         t   ",

};
