#include "read.h"
#include "../../../../../libs/headers/raygui.h"

void drawAbsensiPengajarRead(windowModel *windowM)
{
    int cell_width = 250;
    int cell_height = 50;
    int start_x = 300 + 1620 / 2;
    int start_y = 1080 / 2 - 300;
    int padding = 5;
    int font_size = 32;
    switch (windowM->pengajarHomeState.absensiPage.activeSubWindow)
    {
    case MAIN:
        DrawTextEx(windowM->fontStyle.regular, "PILIH JADWAL",
                   (Vector2){start_x - 225,
                             start_y - 150},
                   64, 0,
                   SIBELAWHITE);

        for (int row = 0; row < windowM->datas.nJadwalPertemuan; row++)
        {
            if (windowM->curPos == row && row < windowM->datas.nJadwalPertemuan)
            {
                windowM->focusedData.jadwal = windowM->datas.jadwalPertemuans[row];
            }
            DrawMeetingPengajarCard(windowM->datas.jadwalPertemuans[row], (Vector2){start_x - 400, start_y + row * 200}, 800, windowM->fontStyle, windowM->curPos == row);
        }
        DrawTextEx(windowM->fontStyle.regular, TextFormat("Halaman %d dari %d", windowM->datas.page, windowM->datas.totalPages),
                   (Vector2){300 + (1620 / 2 - 50),
                             1000},
                   40, 0,
                   SIBELAWHITE);
        break;

    case PRESENSI:
        for (int i = 0; i < windowM->datas.nMuridAbsensi; i++)
        {
            if (windowM->curPos == i)
            {
                DrawRectangleRounded((Rectangle){start_x - 325 - 15,
                                                 start_y - 150 - 10 + i * 50, .width = 100, .height = 80},
                                     0.4, 0, PRIMARY);
                if (!windowM->datas.muridAbsensis[i].isHadir)
                {
                    Rectangle input = {.x = start_x - 225 + 150,
                                       .y = start_y - 150 - 10 + i * 50,
                                       .width = 300,
                                       .height = 32};
                    GuiTextBox(input, windowM->datas.muridAbsensis[i].alasan, 42, CheckCollisionPointRec(windowM->mousePosition, input));
                }
            }
            DrawTextEx(windowM->fontStyle.regular, TextFormat("%s %s", windowM->datas.muridAbsensis[i].nama_murid, windowM->datas.muridAbsensis[i].isHadir ? "HADIR" : "Belom"),
                       (Vector2){start_x - 225,
                                 start_y - 150 + i * 50},
                       64, 0,
                       SIBELAWHITE);

            Rectangle submitButton = {.x = 1920 / 2 - 100,
                                      .y = 1080 - 150,
                                      .width = 200,
                                      .height = 80};
            if (GuiButton(submitButton, "Submit"))
            {
                windowM->pengajarHomeState.absensiPage.submitFunc(windowM->datas.muridAbsensis, windowM->datas.nMuridAbsensi, windowM->focusedData.jadwal.id_pertemuan, windowM->dbConn, windowM->authUser);
            }
        }
        break;
    }
}