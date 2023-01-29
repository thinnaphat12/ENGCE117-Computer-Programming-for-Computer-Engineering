//นายทินภัทร แก้วชมภู 65543206014-4 Sec 1
//https://youtu.be/4j2uzDZOjjw

#include <stdio.h>

struct Element
{
    int data;
    Element *next;
};

Element *beginning = NULL;

void AddElement(Element **head_ref, int new_data);
void UpdateData(Element **head_ref, int search_value, int new_value);
void DisplayAll(Element *head);
void SwapElements(Element **head_ref, int x, int y);
void DisplayBackRecursive(Element *head);
void DisplayBack(Element *head);

int main()
{
    AddElement(&beginning, 40);
    AddElement(&beginning, 30);
    AddElement(&beginning, 20);
    AddElement(&beginning, 10);

    printf("Tihs AddElement : ");
    DisplayAll(beginning);   
    UpdateData(&beginning, 10,99);
    printf("Tihs UpdateData : ");
    DisplayAll(beginning);
    printf("This UpdateDataRecursive : ");
    UpdateData(&beginning, 99,10);
    DisplayAll(beginning);
    printf("This SwapElements 1 : ");
    SwapElements(&beginning,20,30);
    DisplayAll(beginning);
    printf("This SwapElements 2 : ");
    SwapElements(&beginning,10,40);
    DisplayAll(beginning);
    printf("This Showback : ");
    DisplayBack(beginning);
    return 0;
}
void AddElement(Element **head_ref, int new_data)
{
    Element *new_element = new Element();
    new_element->data = new_data;
    new_element->next = (*head_ref);
    (*head_ref) = new_element;
}
void UpdateData(Element **head_ref, int search_value, int new_value)
{
    Element *temp = *head_ref;
    while (temp != NULL)
    {
        if (temp->data == search_value)
        {
            temp->data = new_value;
            return;
        }
        temp = temp->next;
    }
   
}
void DisplayAll(Element *head)
{
    Element *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void SwapElements(Element **head_ref, int x, int y)
{
    if (x == y)
        return;

    Element *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    Element *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    Element* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp; 
}
void DisplayBackRecursive(Element *head){
     if (head == NULL) return;
    DisplayBackRecursive(head->next);
    printf("%d ", head->data);
}
void DisplayBack(Element *head) {
    DisplayBackRecursive(head);
    printf("\n");
}