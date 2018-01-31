#include "stdafx.h"
#include "pageWPF.h"
#include <windows.h>
#include <CommCtrl.h>
#include <string.h>
//Version 5

pageWPF::pageWPF() {}

pageWPF::pageWPF(int setWidth, int setHeight) {

    Grid ^myGrid = gcnew Grid();
    array<ColumnDefinition ^> ^ columnDef = gcnew array<ColumnDefinition ^>(10);
    array<RowDefinition ^> ^ rowDef = gcnew array<RowDefinition ^>(200);

    ScrollViewer ^myWindow = gcnew ScrollViewer();
    StackPanel ^myStackPanel = gcnew StackPanel();
    this->Height = setHeight;
    this->Width = setWidth;

    this->Background = gcnew SolidColorBrush(Colors::LightGray);
    /*
    Create colums & ros for Grid
    */
    for (int i = 0; i < 10; i++)
    {
        columnDef[i] = gcnew ColumnDefinition();
        columnDef[i]->Width = GridLength(1, GridUnitType::Auto);
        myGrid->ColumnDefinitions->Add(columnDef[i]);
    }
    for (int i = 0; i < 200; i++)
    {
        rowDef[i] = gcnew RowDefinition();
        rowDef[i]->Height = GridLength(1, GridUnitType::Auto);
        myGrid->RowDefinitions->Add(rowDef[i]);
    }

    myGrid->Width = setWidth;
    myGrid->HorizontalAlignment = System::Windows::HorizontalAlignment::Left;
    myGrid->VerticalAlignment = System::Windows::VerticalAlignment::Top;
    myGrid->ShowGridLines = true;

    myWindow->Height = setHeight;
    myWindow->Width = setWidth;

    /*
    Create ComboBox and Add Items
    */
    myCombo = CreateCombo(0, 0);
    myCombo->Items->Add("Item 1");
    myCombo->Items->Add("Item 2");
    myCombo->Items->Add("Item 3");
    myCombo->Items->Add("Item 4");
    myCombo->Items->Add("Item 5");

    /*
    Create Labels and Add it to Grid
    */
    myGrid->SetColumnSpan(myCombo, 2);
    ID = CreateLabel(0, 2, "ID");
    label1 = CreateLabel(1, 2, "Label 1");
    label2 = CreateLabel(2, 2, "Label 2");

    label3 = CreateLabel(3, 2, "Label 3");
    label4 = CreateLabel(4, 2, "Label 4");
    label5 = CreateLabel(5, 2, "Label 5");
    label6 = CreateLabel(6, 2, "Label 6");
    label7 = CreateLabel(7, 2, "Label 7");
    myButton = CreateButton(2, 0, L"Check");

    myGrid->Children->Add(ID);
    myGrid->Children->Add(myCombo);
    myGrid->Children->Add(label1);
    myGrid->Children->Add(label2);
    myGrid->Children->Add(label3);
    myGrid->Children->Add(label4);
    myGrid->Children->Add(label5);
    myGrid->Children->Add(label6);
    myGrid->Children->Add(label7);
    for (int i = 1; i < 100; i++) {
        ID = CreateLabel(0, i + 2, i.ToString());
        myGrid->Children->Add(ID);
    }

    myGrid->Children->Add(myButton);

    myStackPanel->Children->Add(myGrid);
    this->Children->Add(myWindow);

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
ComboBox ^pageWPF::CreateCombo(int column, int row) {
    ComboBox ^newCombo = gcnew ComboBox();
    Grid::SetColumn(newCombo, column);
    Grid::SetRow(newCombo, row);
    return newCombo;
}
Label ^pageWPF::CreateLabel(int column, int row, String ^ text)
{
    Label ^ newLabel = gcnew Label();
    newLabel->Content = text;
    newLabel->Margin = Thickness(10, 5, 10, 0);
    newLabel->FontWeight = FontWeights::ExtraBold;
    newLabel->FontSize = 12;
    //newLabel->Background = gcnew SolidColorBrush(Colors::Gray);
    Grid::SetColumn(newLabel, column);
    Grid::SetRow(newLabel, row);
    return newLabel;
}
