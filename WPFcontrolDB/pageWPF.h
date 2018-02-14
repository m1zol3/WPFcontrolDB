#pragma once
#include "stdafx.h"
 
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Navigation;
using namespace System::Windows::Documents;
using namespace System::Threading;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;
 
public ref class  DBPageEventArgs : EventArgs
{
public:
     DBPageEventArgs();
     DBPageEventArgs(bool Okay);

    property bool isOkay;
     
};
public ref class pageWPF : public Grid {
private:
    Label ^ID, ^label1, ^label2, ^label3, ^label4, ^label5, ^label6, ^label7, ^label8;
    Button ^okayButton, ^cancelButton;
    List myList;
   bool handle = true;
public:
    delegate void ButtonClickHandler(Object ^, DBPageEventArgs ^);
    event ButtonClickHandler ^OnButtonClicked;
 
    pageWPF();
    pageWPF(int height, int width);
    
    ScrollViewer ^ myScroll;
    Button ^ myButton;
    ComboBox ^ myCombo;
    ComboBoxItem ^myItem;
    Label ^ CreateLabel(int column, int row, String ^text);
    void ButtonClicked(Object ^ sender, RoutedEventArgs ^ args);
    Grid ^myGrid;
    TextBox ^myText;
    
    Button ^CreateButton(int column, int row, String ^text);
    ComboBox ^CreateCombo(int column, int row);
    ComboBoxItem ^CreateMyItem( String ^name, String ^text);
    TextBox ^ CreaTextBlock(int column, int row);
};
