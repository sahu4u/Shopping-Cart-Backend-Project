#include <iostream>
#include "datamodel.h"
#include<vector>

vector<Product> allProducts={
    Product(1,"apple",26),
    Product(3,"mango",16),
    Product(2,"guava",36),
    Product(5,"banana",56),
    Product(4,"Strawberry",29),
    Product(6,"pineapple",77),
    Product(10,"orange",7),
};


Product* chooseProduct(){

    string productList;
    cout<<" Available Products "<<endl;

    for(auto product:allProducts){
        productList.append(product.getDisplayName());
        cout<<product.getDisplayName();
    }


    cout<<"-------------------------------"<<endl;

    string choice;
    cin>>choice;

    //Linear Search Algorithm

    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found : "<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty())
    {
        cout<<"Your cart is empty. Please add the items to the cart"<<endl;
        return false;
    }

    int total=cart.getTotal();
    cout<<"Pay in cash...";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change Rs. "<<paid-total<<endl;
        cout<<"Thank you for shopping with us!!"<<endl;
    }
    else{
        cout<<"Not enough cash!!"<<endl;
        return false;
    }

    return true;
    
}


int main(){

    char action;  
    Cart cart;      
    while(true){
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;

        if(action=='a'){
            //Add to cart
            //View all the products+ Choose Product + Add to the Cart
            Product* product=chooseProduct();
            if(product!=NULL)
            {
                cout<<"Added to the Cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);

            }



        }
        else if(action=='v'){
            cout<<"-------------------------------"<<endl;
            cout<<cart.viewcart()<<endl;
            cout<<"-------------------------------"<<endl;
            //View the Cart
            
        }
        else {
            //Check-out
             cout<<cart.viewcart()<<endl;
             if(checkout(cart)){
                break;
             }
        }
    }
        

        return 0;
}