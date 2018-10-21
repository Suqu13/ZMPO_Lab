//
// Created by Jakub on 08.10.2018.
//

#define CATCH_CONFIG_MAIN

#include "../lib/catch.hpp"
#include "../ctab/CTable.h"


SCENARIO("Test constructor") {
    GIVEN("CTable object") {
        WHEN("default constructor is called") {
            CTable table;

            THEN("objects fields should have appropriate values") {
                REQUIRE(table.sGetName() == "Regular_CTable");
                REQUIRE(table.iGetLength() == 10);
            }
        }

        WHEN("parameter constructor is called") {
            CTable table("MyTable", 12);

            THEN("objects fields should have appropriate values") {
                REQUIRE(table.sGetName() == "MyTable");
                REQUIRE(table.iGetLength() == 12);
            }
        }

        AND_GIVEN("Another CTable object") {
            CTable cpyThis("Table", 3);
            CTable cpyThis_em("Em_Table", 0);
            REQUIRE(cpyThis.bInsertElement(0, 1));
            REQUIRE(cpyThis.bInsertElement(1, 2));
            REQUIRE(cpyThis.bInsertElement(2, 3));

            WHEN("copying constructor is called") {
                CTable table(cpyThis);
                CTable Em_Table(cpyThis_em);

                THEN("objects fields should have appropriate values") {
                    REQUIRE(table.sGetName() == "Table_copy");
                    REQUIRE(table.iGetLength() == 3);

                    bool success = false;
                    REQUIRE(table.sToString() == "[1, 2, 3]");
                    REQUIRE(Em_Table.sToString() == "[]");
                    REQUIRE(table.iGetElement(0, &success) == 1);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(1, &success) == 2);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(2, &success) == 3);
                    REQUIRE(success);
                }
            }
        }
    }
}

//Operator

SCENARIO("Test set name") {
    GIVEN("CTable object") {
        CTable table;

        WHEN("It's name is changed") {
            table.vSetName("MyTable");

            THEN("It should change") {
                REQUIRE(table.sGetName() == "MyTable");
            }
        }
    }
}

SCENARIO("Test set length") {
    GIVEN("CTable object") {
        CTable table("Whatever", 5);

        WHEN("it's fields are set") {
            REQUIRE(table.bInsertElement(0, 1));
            REQUIRE(table.bInsertElement(1, 2));
            REQUIRE(table.bInsertElement(2, 3));
            REQUIRE(table.bInsertElement(3, 4));
            REQUIRE(table.bInsertElement(4, 5));

            AND_WHEN("it's size is expanded") {
                REQUIRE(table.bSetLength(10));

                GIVEN("success variable") {
                    bool success = false;

                    THEN("check new fields are 0") {
                        REQUIRE(table.iGetElement(5, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.iGetElement(6, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.iGetElement(7, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.iGetElement(8, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.iGetElement(9, &success) == 0);
                        REQUIRE(success);
                    }

                    AND_WHEN("new fields are changed") {
                        REQUIRE(table.bInsertElement(5, 11));
                        REQUIRE(table.bInsertElement(6, 12));
                        REQUIRE(table.bInsertElement(7, 13));
                        REQUIRE(table.bInsertElement(8, 14));
                        REQUIRE(table.bInsertElement(9, 15));

                        THEN("make sure all fields have proper values") {
                            REQUIRE(table.iGetElement(0, &success) == 1);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(1, &success) == 2);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(2, &success) == 3);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(3, &success) == 4);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(4, &success) == 5);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(5, &success) == 11);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(6, &success) == 12);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(7, &success) == 13);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(8, &success) == 14);
                            REQUIRE(success);
                            REQUIRE(table.iGetElement(9, &success) == 15);
                            REQUIRE(success);
                        }
                    }
                }
            }

            AND_WHEN("it's size is truncated") {
                REQUIRE(table.bSetLength(3));

                GIVEN("success variable") {
                    bool success = true;

                    THEN("left out fields values shouldn't change") {
                        REQUIRE(table.iGetElement(0, &success) == 1);
                        REQUIRE(table.iGetElement(1, &success) == 2);
                        REQUIRE(table.iGetElement(2, &success) == 3);
                    }

                    AND_WHEN("illegal value is accessed") {
                        REQUIRE(table.iGetElement(3, &success) == -1);

                        THEN("it shouldn't be successful") {
                            REQUIRE_FALSE(success);
                        }
                    }
                }
            }

            AND_WHEN("unreasonable argument is passed to set length method") {
                REQUIRE_FALSE(table.bSetLength(-15));

                THEN("nothing should change") {
                    bool success = false;
                    REQUIRE(table.iGetElement(0, &success) == 1);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(1, &success) == 2);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(2, &success) == 3);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(3, &success) == 4);
                    REQUIRE(success);
                    REQUIRE(table.iGetElement(4, &success) == 5);
                    REQUIRE(success);
                }
            }
        }
    }
}

SCENARIO("Test accessing elements") {
    GIVEN("CTable object and variable indicating success") {
        CTable table;
        bool success = false;

        WHEN("It's elements are changed") {
            AND_WHEN("They are within legal range") {
                THEN("They should change") {
                    REQUIRE(table.bInsertElement(0, 15));
                    REQUIRE(table.iGetElement(0, &success) == 15);
                    REQUIRE(success);
                    REQUIRE(table.bInsertElement(0, 16));
                    REQUIRE(table.iGetElement(0, &success) == 16);
                    REQUIRE(success);
                    REQUIRE(table.bInsertElement(9, 9));
                    REQUIRE(table.iGetElement(9, &success) == 9);
                    REQUIRE(success);
                }
            }

            AND_WHEN("They aren't within legal range") {
                THEN("They shouldn't change") {
                    REQUIRE_FALSE(table.bInsertElement(-12, 14));
                    REQUIRE(table.iGetElement(-12, &success) == -1);
                    REQUIRE_FALSE(success);
                }
            }
        }
    }
}

SCENARIO("Test cClone") {
    GIVEN("CTable object") {
        CTable table("Name", 3);
        REQUIRE(table.bInsertElement(0, 1));
        REQUIRE(table.bInsertElement(1, 2));
        REQUIRE(table.bInsertElement(2, 3));

        WHEN("It's cloned") {
            CTable *cloned = table.cClone();

            THEN("Those objects should be in different places in memory") {
                REQUIRE_FALSE(cloned == &table);
            }

            THEN("Should have all fields same") {
                bool success = true;
                REQUIRE(table.sGetName() + "_copy" == cloned->sGetName());
                REQUIRE(table.iGetLength() == cloned->iGetLength());
                REQUIRE(table.iGetElement(0, &success) == cloned->iGetElement(0, &success));
                REQUIRE(table.iGetElement(1, &success) == cloned->iGetElement(1, &success));
                REQUIRE(table.iGetElement(2, &success) == cloned->iGetElement(2, &success));
            }

            delete cloned; //why do I need to specify this? because it's stored as a pointer?
        }
    }
}

SCENARIO("Test operator =") {
    GIVEN("CTable object to be copied") {
        CTable toCpy("To copy", 3);
        REQUIRE(toCpy.bInsertElement(0, 1));
        REQUIRE(toCpy.bInsertElement(1, 2));
        REQUIRE(toCpy.bInsertElement(2, 3));

        AND_GIVEN("CTable object copying") {
            CTable table("Copying", 6);
            REQUIRE(table.bInsertElement(0, 6));
            REQUIRE(table.bInsertElement(1, 5));
            REQUIRE(table.bInsertElement(2, 4));
            REQUIRE(table.bInsertElement(3, 3));
            REQUIRE(table.bInsertElement(4, 2));
            REQUIRE(table.bInsertElement(5, 1));

            WHEN("Using = operator") {
                table = toCpy;

                THEN("CTables objects array changes") {
                    REQUIRE(table.sGetName() == "Copying");
                    REQUIRE(table.iGetLength() == 3);

                    bool success = true;
                    REQUIRE(table.iGetElement(0, &success) == 1);
                    REQUIRE(table.iGetElement(1, &success) == 2);
                    REQUIRE(table.iGetElement(2, &success) == 3);
                }
            }
        }
    }
}

SCENARIO("Test toString") {
    GIVEN("CTable object") {
        CTable table("Name", 3);

        WHEN("It's values are set") {
            table.bInsertElement(0, 1);
            table.bInsertElement(1, 2);
            table.bInsertElement(2, 3);

            THEN("It's toString should show everything properly") {
                REQUIRE(table.sToString() == "[1, 2, 3]");
            }
        }
    }
}

SCENARIO("Test vColapse") {
    GIVEN("CTable object") {
        CTable table("Name", 5);

        WHEN("It's values are set") {
            table.bInsertElement(0, 1);
            table.bInsertElement(1, 2);
            table.bInsertElement(2, 3);
            table.bInsertElement(3, 4);
            table.bInsertElement(4, 5);

            THEN("It's vColapse should divide and colapse") {
                table.vColapse();
                bool bSucc = true;
                REQUIRE(table.iGetElement(0, &bSucc) == 5);
                REQUIRE(table.iGetElement(1, &bSucc) == 7);
                REQUIRE(table.iGetElement(2, &bSucc) == 3);


            }
        }
    }
}