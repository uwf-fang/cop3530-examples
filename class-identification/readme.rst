
********************
Class identification
********************

Introduction
============

If you have done some search on class identification in object-oriented
programming, you will know that there are many methods to achieve this purpose.
It takes tests and experience to find one method that works best for you. The
method described here is only my personal understanding of what works well for
students in teaching.

My Recommended Method
=====================

1. Tell the story in detail

   + Also known as "user story", similar to the concept of "specification" and
     "requirement"
   + Be very detailed from many perspective
   + It is a simpler way compare to "use case" method and is usually good
     enough for a small project

2. Extract meaningful keywords (concepts)

   + nouns, verbs, and sometimes adjectives

3. Check keywords against rules to categorize them into the group of objects,
   attributes and behaviors;

   + A good object is an aggregation of attributes and behaviors;
   + Attributes and behaviors in one object should be related (e.g. attributes
     being the subject or object of the behaviors, a.k.a. coherence);
   + An attribute may also be an object as an object can own another object;
   + Make sure the keywords are within the boundary of the software; Sometimes
     you will need to discard keywords that are actually inter-actor from
     outside of your software;

4. Identify the relationships among all keywords (concepts)

5. Generalize objects to classes (C++ is a class-based OOP language)

   + Objects that share same attributes and behaviors can be described as a
     class;
   + A class is a blue print of a group of objects and an object is an instance
     of a class;

6. Review and confirm, repeat step 1-5 if necessary.

   + The identification process is purely problem dependent. One keyword may be
     a class in this system but an attribute in another system; Therefore,
     check carefully;
   + Check if you have missed any part of the user story;

How to learn
============

Just practice. Imagine realistic problems to solve and practice class
identifications on these problems.

Notations
=========

The UML (unified modeling language) class diagram notations here.

+ ``+`` to represent public
+ ``-`` to represent public
+ ``name: type`` to indicate an instance variable with a ``name`` and a
  ``type``
+ ``methodName(parameterName: parameterType, ...): returnType`` to represent a
  method ``methodName`` with a ``returnType``. Return type can be omitted for
  void method or constructors.

Example
=======

1. Story

   Develop a software to manage a restaurant. When a customer visit the
   restaurant, he review the menu first and place an order. The order will be
   delivered first and then paid. Menu holds menu items with prices listed. The
   customer can order multiple servings of a same item. The manager can add,
   remove, modify items in the menu.

   Some assumption: Restaurant has a unique name. Only one menu is used. The
   items in an order is delivered together.

2. Keywords/Concepts

   + nouns: restaurant, menu, customer, order, food(item), price, quantity
   + verbs: visit, read(show), place, deliver, pay

3. Categorize

   + out of boundary: customer, visit
   + classes: Restaurant, Order, Menu, MenuItem, Item
   + attributes: name(restaurant), name(item), price, quantity
   + behaviors: show (menu), place (order), deliver (food)

4. Relationships

   + A restaurant manages a name, a menu, many orders; manages orders
   + A menu owns menu items, shows itself, adds/removes/modifies menu items
   + A menu item owns name, and price
   + An order owns order items, adds/removes/modify quantities of items
   + An order can be placed, delivered and paid
   + An order item owns reference to the menu item and quantity

5. Generalize to class (plural form noun means a vector, an array or a
   collection)

   + Restaurant class

     * - menu: Menu
     * - name: string
     * - pendingOrders: list/array/vector of Order objects
     * - finishedOrders: list/array/vector of Order objects
     * + Restaurant()
     * + Restaurant(name: string)
     * + setName(name: string)
     * + getName(): string
     * + setMenu(menu: Menu)
     * + showMenu(): string
     * + place(orderId: int)
     * + pay(orderId: int)
     * + deliver(orderId: int)

   + Menu class

     * - items: array or vector of Item objects
     * - count: int (optional for items types carries its owns size)
     * + add(name: string, price: double)
     * + remove(id: int)
     * + show(): string
     * + find(name: string): int

   + Order class

     * - id: int
     * - items: array or vector of Item objects
     * - count: int (optional for items types carries its owns size)
     * - ready: bool
     * - delivered: bool
     * - paid: bool
     * + Order()
     * + add(name: string, quantity: int)
     * + remove(name: string, quantity: int): bool (may fail)
     * + deliver()
     * + pay()
     * + show(): string

   + Item class

     * - menuItemId: int
     * - quantity: int
     * + Item()
     * + Item(menuItemId: int, quantity = 1: int)
     * + show(): string

   + MenuItem class

     * - id: int
     * - name: string
     * - price: double
     * + Item()
     * + Item(name: string, price: double)
     * + show(): string

6. Review and improve

   + missing parts

     * order item may need to report item name

   + improve implementation

     * naming like show() can be changed to to_str() to align to the convention

