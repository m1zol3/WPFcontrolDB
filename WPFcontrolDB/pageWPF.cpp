#include "stdafx.h"
#include "pageWPF.h"
 
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
        ID = CreateLabelID(1, i+1, (i+1).ToString());
        this->Children->Add(ID);
    }
    ID = CreateLabel(1, 0, "ID");
    this->Children->Add(ID);
    firstname = CreateLabel(2, 0, "Vorname");
    this->Children->Add(firstname);
    lastname = CreateLabel(3,0, "Name");
    this->Children->Add(lastname);
    status = CreateLabel(4, 0, "Status");
    this->Children->Add(status);
    teamPool = CreateLabel(5, 0, "Pool Mannschaft");
    this->Children->Add(teamPool);
    teamSnooker = CreateLabel(6, 0, "Snooker Mannschaft");
    this->Children->Add(teamSnooker);
    date = CreateLabel(7, 0, "Eintrittsdatum");
    this->Children->Add(date);
 

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
 