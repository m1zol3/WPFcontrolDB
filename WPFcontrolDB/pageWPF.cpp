#include "stdafx.h"
#include "pageWPF.h"
#include <windows.h>
#include <CommCtrl.h>

 //Version 5
  
pageWPF::pageWPF(){}

pageWPF::pageWPF(int setWidth, int setHeight ) {
    array<ColumnDefinition ^> ^ columnDef = gcnew array<ColumnDefinition ^>(8);
    array<RowDefinition ^> ^ rowDef = gcnew array<RowDefinition ^>(200);
 
    this->Height = setHeight;
    this->Width = setWidth;
    this->Background = gcnew SolidColorBrush(Colors::LightGray);
    for (int i = 0; i<8; i++)
    {
        columnDef[i] = gcnew ColumnDefinition();
        columnDef[i]->Width = GridLength(1, GridUnitType::Auto);
        this->ColumnDefinitions->Add(columnDef[i]);
    }
    for (int i = 0; i<200; i++)
    {
        rowDef[i] = gcnew RowDefinition();
        rowDef[i]->Height = GridLength(1, GridUnitType::Auto);
        this->RowDefinitions->Add(rowDef[i]);
    }
   /* myButton = CreateButton(0, 0, "Hallo");
    this->Children->Add(myButton);
   */ 
    ID = CreateLabel(0, 1, "ID");
    this->Children->Add(ID);
    firstname = CreateLabel(1, 1, "Vorname");
    this->Children->Add(firstname);
    lastname = CreateLabel(2,1, "Name");
    this->Children->Add(lastname);
    status = CreateLabel(3, 1, "Status");
    this->Children->Add(status);
    teamPool = CreateLabel(4, 1, "Pool Mannschaft");
    this->Children->Add(teamPool);
    teamSnooker = CreateLabel(5, 1, "Snooker Mannschaft");
    this->Children->Add(teamSnooker);
    date = CreateLabel(6, 1, "Eintrittsdatum");
    this->Children->Add(date);
  
    myCombo = CreateCombo(1,0, "klh");
    this->Children->Add(myCombo);
    
    CreateItem("Alle");
    CreateItem("Aktiv");
    CreateItem("Passiv");
    CreateItem("Gast");
    CreateItem("Ehemalige");


    for (int i = 1 ;i<200;i++){
    ID = CreateLabelID(0, i+1, (i).ToString());
    this->Children->Add(ID);
    }

   


}
Button ^pageWPF::CreateButton(int column, int row, String ^text) {
    Button ^newButton = gcnew Button();
    newButton->Content = text;
    newButton->Name = text;
    Grid::SetColumn(newButton, column);
    Grid::SetRow(newButton, row);
    return newButton;
}
Label ^pageWPF::CreateLabel(int column, int row, String ^ text)
{
    Label ^ newLabel = gcnew Label();
    newLabel->Content = text;
    newLabel->Margin = Thickness(10, 5, 10, 0);
    newLabel->FontWeight = FontWeights::ExtraBold;
    newLabel->FontSize = 18;
    newLabel->Background = gcnew SolidColorBrush(Colors::Gray);
    Grid::SetColumn(newLabel, column);
    Grid::SetRow(newLabel, row);
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
