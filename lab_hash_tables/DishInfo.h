/*
 * CS15 Lab 10: Hash Tables
 * 
 * DishInfo.h
 * This struct represents the values for the hash tables in 
 * TurkeyChainingTable and TurkeyLinearTable. The dish name 
 * (strings) are keys and the values are structs containing the 
 * serving size and preparation time in minutes.
 * 
 */

/* Adding include guard for lab to avoid 
   multiple definition with both tables */
#ifndef DISH_INFO_H 
#define DISH_INFO_H

struct DishInfo {
        int servingSize;
        int prepTime;

        /* Constructors for struct */
        DishInfo() 
        {
                servingSize = prepTime = -1;
        }

        DishInfo(int servings, int minutes)
        {
                servingSize     = servings;
                prepTime        = minutes;
        }
};

#endif    /* DISH_INFO_H */