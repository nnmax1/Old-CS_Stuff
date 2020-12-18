
//Project 1: Word Unscrambler Game

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Random;
import java.util.Arrays;

public class Project1 {

    public static void main(String args[]) throws IOException {  
      //fileinputstream object
      FileInputStream in = null;
      //arraylist to store words from words.txt file
      ArrayList<String> words = new ArrayList<String>();
       //must use FileInputStream obj in a try block b/c it could
       //throw a FileNotFoundException
      try {
         //init the fileinputstream object with file words.txt
         in = new FileInputStream("words.txt");
         //create Scanner object with Fileinput stream object
         Scanner scan = new Scanner(in);
         //read data from words.txt and store each word into the
         //ArrayList called words
         while (scan.hasNextLine()) {
            String line = scan.next();
            words.add(line);
         }
      //catch FileNotFoundException if thrown
      }catch(FileNotFoundException ex) {
         //print the exception
         System.out.println(ex);
      }
      //use Random() to generate a random index
      Random rand = new Random();
      int randIndex = rand.nextInt(words.size()-1);
      //get a random word from the ArrayList
      String unscrambledWord = words.get(randIndex);
      //scramble the word using the method wordScrambler()
      String scrambledWord = wordScrambler(unscrambledWord);
      //use the scrambled and unscrambled word to play the game
      playGame(scrambledWord, unscrambledWord);
    }
    //function to play a game (needs scrambled and unscrambled words as parameters)
    //the parameter u is the unscrambled word represented as a string
   public static void  playGame(String s, String u) {
      //convert from String to c-strings
      char unscrambled[] = u.toCharArray();
      char scrambled[] = s.toCharArray();
      //set gameOver to true when the game is over
      boolean gameOver = false;
      //keeps track of how many steps player took to unscramble the word
      int counter =0;
      //Scanner object to read input from the console
      Scanner scnr = new Scanner(System.in);
      System.out.println("Word Unscrambler Game");
      //play the game while gameOver is false
      while(!gameOver){
         //display the word
         showWord(scrambled);
         //display menu options
         menu();
         //get user's choice based on menu options
         int choice = scnr.nextInt();
         //process the choice using a switch statement
         switch(choice){
            case 1:
               counter++;
               //get indices for swapping from user
               System.out.println("Enter the indices separated by a space: ");
               int i1 = scnr.nextInt();
               int i2 = scnr.nextInt();
               //check if the indices are valid before swapping
               if(i1 >= 0 && i1 < scrambled.length && i2 >= 0 && i2 < scrambled.length) {
                  //swap indices
                  swap(scrambled, i1, i2);
                  //check if the scrambled word equals the unscrambled word after the swap
                  //if it does, end the game. Otherwise keep playing 
                  if(Arrays.equals(scrambled, unscrambled)){
                     System.out.println("Congratulations! You unscrambled the word "+u+" in "+counter+" steps.");
                     gameOver =true;
                  }
               }else {
                  System.out.println("Invalid indices");
               }
            break;
            case 2:
               counter++;
               //get the word from the user
               System.out.println("Enter the word: ");
               scnr = new Scanner(System.in);
               String temp = scnr.nextLine();
               //check if the word equals the unscrambled word. if so, end the game
               if(temp.equals(u)) {
                  System.out.println("Congratulations! You unscrambled the word "+u+" in "+counter+" steps.");
                  gameOver =true;
               }
            break;
            case 3:
               //quit the game and print to the console 
               //what the unscrambled word was
               System.out.println("The word was: "+ u);
               System.out.println("You quit the game");
               gameOver=true;
            break;
            default:
               System.out.println("Invalid option");
            break;
         }
       }
    }
    //displays the game menu options
   private static void menu() {
      System.out.println("Enter 1 to swap letters.");
      System.out.println("Enter 2 to solve.");
      System.out.println("Enter 3 to quit.");
    }
    //show a word
    private static void showWord(char w[]) {
       //print out dashes above the word
       for(int i=0;i<w.length;i++) {
          System.out.print("-");
       }System.out.println();
       //print the word's indices
       for(int i=0;i<w.length;i++) {
         System.out.print(i);
      }System.out.println();
      //print the word itself
      for(int i=0;i<w.length;i++) {
          System.out.print(w[i]);
       }System.out.println();
       //print dashes below the word
       for(int i=0;i<w.length;i++) {
         System.out.print("-");
      }System.out.println();
    } 
    //function returns a scramble a word
    private static String wordScrambler(String word) {
       //convert string to a c-string
       char arr[] = word.toCharArray();
       //iterate over the word and swap letters
       //in the word at random indices
       for(int i=0;i<arr.length;i++) {
          Random r = new Random();
          int j = r.nextInt(arr.length-1);
         swap(arr, i, j);
      }
      //convert c-string back to a string
      String res = new String(arr);
      //return the scrambled word
      return res;
    }
    //swap characters in a c-string
    private static void swap(char arr[], int i, int j) {
       char temp = arr[j];
       arr[j] = arr[i];
       arr[i] = temp;
    }
 }
 