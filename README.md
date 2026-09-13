# Movie-Ticket-Booking-system

A **console-based Movie Ticket Booking System** developed in **C++17** using **Object-Oriented Programming (OOP)** concepts.

The system allows users to view movies and shows, check seat availability, book seats, make payments, view tickets, and cancel confirmed bookings.

## Features

- View currently playing movies
- View available shows for a selected movie
- Display seat layout with seat type and availability
- Book one or more seats
- Calculate ticket price according to seat type
- Support multiple payment methods:
  - UPI
  - Card
  - Cash
- Confirm booking only after successful payment
- Print tickets for confirmed bookings
- View booked tickets
- Cancel confirmed bookings
- Release seats after cancellation
- Validate invalid menu choices and seat numbers
- Handle failed payments safely

## Seat Pricing

| Seat Type | Price |
|-----------|------:|
| Silver | ₹150 |
| Gold | ₹250 |
| Platinum | ₹400 |

The total amount is calculated by adding the price of all selected seats.

## Project Structure

```text
Movie-Ticket-Booking-system/
│
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PaymentTypes.cpp
├── 11_PriceCalculator.cpp
├── 12_TicketPrinter.cpp
├── 13_BookingService.cpp
├── main.cpp
└── demo_output.txt
```

## OOP Concepts Used

- **Classes and Objects**
- **Encapsulation**
- **Inheritance**
- **Polymorphism**
- **Abstraction**
- **Composition and Association**
- **Constructors and Member Functions**
- **Vectors / STL**

## Payment System

The project uses an abstract `Payment` class with different payment implementations:

- `UpiPayment`
- `CardPayment`
- `CashPayment`

A booking is marked as **confirmed only when the payment is successful**.

## Booking Flow

```text
Select Movie
      ↓
Select Show
      ↓
Check Seat Availability
      ↓
Select Seats
      ↓
Calculate Total Price
      ↓
Create Booking
      ↓
Select Payment Method
      ↓
Process Payment
      ↓
Payment Successful?
   ↙          ↘
 Yes           No
  ↓             ↓
Confirm       Cancel/Fail
Booking       Payment
  ↓
Print Ticket
  ↓
Display Ticket
```

## How to Compile

Make sure **g++** and **C++17** are installed.

Compile all source files:

```bash
g++ -std=c++17 *.cpp -o movie_booking
```

Run the program:

### Windows

```bash
movie_booking.exe
```

### Linux / macOS

```bash
./movie_booking
```

## Technologies Used

- **Language:** C++17
- **Programming Paradigm:** Object-Oriented Programming
- **Compiler:** g++
- **STL:** Vector and standard C++ libraries
- **Interface:** Console-based

## Project Purpose

This project demonstrates how OOP principles can be applied to build a real-world **Movie Ticket Booking System**, including movie/show management, seat management, booking, pricing, payment processing, ticket printing, and cancellation.

## Author

**Movie Ticket Booking System — C++17 OOP Project**
