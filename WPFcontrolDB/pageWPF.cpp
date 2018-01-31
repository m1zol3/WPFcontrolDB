#include "stdafx.h"
#include "pageWPF.h"
#include <windows.h>
#include <CommCtrl.h>
#include <string.h>
 //Version 5
  
pageWPF::pageWPF(){}

pageWPF::pageWPF(int setWidth, int setHeight ) {

     array<ColumnDefinition ^> ^ columnDef = gcnew array<ColumnDefinition ^>(8);
     array<RowDefinition ^> ^ rowDef = gcnew array<RowDefinition ^>(200);
     ColumnDefinition ^mycolumnDefOne = gcnew ColumnDefinition();
     ColumnDefinition ^mycolumnDefTwo = gcnew ColumnDefinition();
     ColumnDefinition ^mycolumnDefThree = gcnew ColumnDefinition();
     ScrollViewer ^myWindow = gcnew ScrollViewer();
     StackPanel ^myStackPanel  = gcnew StackPanel();
     Grid ^myGrid = gcnew Grid();

     for (int i = 0; i<8; i++)
     {
         columnDef[i] = gcnew ColumnDefinition();
         columnDef[i]->Width = GridLength(1, GridUnitType::Auto);
         myGrid->ColumnDefinitions->Add(columnDef[i]);
     }
     for (int i = 0; i<200; i++)
     {
         rowDef[i] = gcnew RowDefinition();
         rowDef[i]->Height = GridLength(1, GridUnitType::Auto);
         myGrid->RowDefinitions->Add(rowDef[i]);
     }
      
     myGrid->Width = 600;
     myGrid->HorizontalAlignment = System::Windows::HorizontalAlignment::Left;
     myGrid->VerticalAlignment = System::Windows::VerticalAlignment::Top;
     myGrid->ShowGridLines = true;
     
     


      

     myWindow->Height = setHeight;
     myWindow->Width = setWidth;

    
    this->Height = setHeight;
    this->Width = setWidth;
     
    this->Background = gcnew SolidColorBrush(Colors::LightGray);
 
    //this->Children->Add(status);
    teamPool = CreateLabel(  "Pool Mannschaft");
    //this->Children->Add(teamPool);
    teamSnooker = CreateLabel( "Snooker Mannschaft");
    //this->Children->Add(teamSnooker);
    date = CreateLabel(  "Eintrittsdatum");
    //this->Children->Add(date);
   
     
    //this->Children->Add(myCombo);
    myCombo = CreateCombo(1, 0, "klh");
    CreateItem("Alle");
    CreateItem("Aktiv");
    CreateItem("Passiv");
    CreateItem("Gast");
    CreateItem("Ehemalige");
 



    status = CreateLabel("ID");
    firstname = CreateLabel("Vorname");
    lastname = CreateLabel("Name");
 
    myGrid->SetColumn(status, 0);
    myGrid->SetRow(status, 1);
    myGrid->SetColumn(firstname, 1);
    myGrid->SetRow(firstname, 1);
    myGrid->SetColumn(lastname, 2);
    myGrid->SetRow(lastname, 1);
    myGrid->Children->Add(status);
    myGrid->Children->Add(firstname);
    myGrid->Children->Add(lastname);

     
    
    
    myStackPanel->Children->Add(myGrid);
    
    this->Children->Add(myWindow);// ->Parent = pageWPF;
    
    
    
   
   // myStackPanel->Children->Add(firstname);
  
      for (int i = 1 ;i<100;i++){
        ID = CreateLabelID(0,0, (i).ToString());
        myGrid->SetRow(ID, i+2);
        myGrid->SetColumn(ID, 0);
   
        myGrid->Children->Add(ID);

    } 
  
    myStackPanel->Width = 1000;
    myStackPanel->HorizontalAlignment = System::Windows::HorizontalAlignment::Left;
    myWindow->Content = myStackPanel;
 
   
} 
Button ^pageWPF::CreateButton(int column, int row, String ^text) {
    Button ^newButton = gcnew Button();
    newButton->Content = text;
    newButton->Name = text;
    Grid::SetColumn(newButton, column);
    Grid::SetRow(newButton, row);
    return newButton;
}
Label ^pageWPF::CreateLabel(  String ^ text)
{
    Label ^ newLabel = gcnew Label();
    newLabel->Content = text;
    newLabel->Margin = Thickness(10, 5, 10, 0);
    newLabel->FontWeight = FontWeights::ExtraBold;
    newLabel->FontSize = 18;
    newLabel->Background = gcnew SolidColorBrush(Colors::Gray);
    
    return newLabel;
}
Label ^pageWPF::CreateLabelID(int column, int row, String ^ text)
{
    Label ^ newLabel = gcnew Label();
    newLabel->Content = text;
    newLabel->Margin = Thickness(10, 5, 10, 0);
    newLabel->FontWeight = FontWeights::ExtraBold;
    newLabel->FontSize = 14;
    newLabel->Background = gcnew SolidColorBrush(Colors::Gray);
    Grid::SetColumn(newLabel, column);
    Grid::SetRow(newLabel, row);
    
    return newLabel;
}
ComboBox ^pageWPF::CreateCombo(int column, int row, String ^ text) {
    ComboBox ^newCombo = gcnew ComboBox();
    //newCombo->add
   
    
    Grid::SetColumn(newCombo, column);
    Grid::SetRow(newCombo, row);
    return newCombo;


 }

ComboBoxItem ^ pageWPF::CreateItem(String ^ text)
{
    ComboBoxItem ^newItem = gcnew ComboBoxItem();

    myCombo->Items->Add(text);
    return newItem;
    
}

ListView ^ pageWPF::CreateListView(int setHeigh, int setWidth)
{
    ListView ^myList = gcnew ListView;
    myList->Height = setHeigh;
    myList->Width = setWidth;
    return myList;
    // TODO: hier Rückgabeanweisung eingeben
}

ScrollViewer ^ pageWPF::CreatScroll(int setWidth, int setHeigh)
{
    ScrollViewer ^myScroll = gcnew ScrollViewer();
    myScroll->Width = setWidth -30 ;
    myScroll-> Height = setHeigh -30;
    return myScroll;
    // TODO: hier Rückgabeanweisung eingeben
}
 