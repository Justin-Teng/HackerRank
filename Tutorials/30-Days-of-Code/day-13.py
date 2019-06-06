from abc import ABCMeta, abstractmethod
class Book(object, metaclass=ABCMeta):
    def __init__(self,title,author):
        self.title=title
        self.author=author   
    @abstractmethod
    def display(): pass
class MyBook(Book):
    
    def __init__(self, title, author, price):
        super(Book, self).__init__()
        self.price  = price
    
    def display(self):
        print("Title: {}".format(title))
        print("Author: {}".format(author))
        print("Price: {}".format(price))
title=input()
