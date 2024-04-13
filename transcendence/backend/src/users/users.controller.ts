import {
  Body,
  ClassSerializerInterceptor,
  Controller,
  Delete,
  FileTypeValidator,
  Get,
  MaxFileSizeValidator,
  Param,
  ParseFilePipe,
  ParseIntPipe,
  Patch,
  Post,
  Req,
  UploadedFile,
  UseGuards,
  UseInterceptors,
} from '@nestjs/common';
import { FileInterceptor } from '@nestjs/platform-express';
import { ApiBearerAuth, ApiTags } from '@nestjs/swagger';
import { JwtTwoFactorGuard } from '../auth/2fa/2fa.guard';
import { AccessTokenGuard } from '../auth/jwt/jwt.guard';
import { RequestTypeWithUser } from '../auth/types/auth.interface';
import { CreateUserDto } from './types/create-user.dto';
import { UpdateUserDto } from './types/update-user.dto';
import { UsersService } from './users.service';
@ApiTags('users')
@ApiBearerAuth()
@UseInterceptors(ClassSerializerInterceptor)
@Controller('users')
export class UsersController {
  constructor(private readonly usersService: UsersService) {}

  /**
   * List all users
   */
  @Get()
  @UseGuards(JwtTwoFactorGuard)
  findAll() {
    return this.usersService.findAll();
  }

  @Get('me')
  @UseGuards(AccessTokenGuard)
  findMe(@Req() req: RequestTypeWithUser) {
    const user = req.user;
    return this.usersService.findOne(user.id);
  }

  @Get(':id')
  @UseGuards(JwtTwoFactorGuard)
  findOne(@Param('id', ParseIntPipe) id: number) {
    return this.usersService.findOne(id);
  }

  @Get(':id/stats')
  @UseGuards(JwtTwoFactorGuard)
  getGameStats(@Param('id') id: number) {
    return this.usersService.getGameStats(id);
  }

  @Get(':id/match-history')
  @UseGuards(JwtTwoFactorGuard)
  getMatchHistory(@Param('id') id: number) {
    return this.usersService.getMatchHistory(id);
  }

  /**
   * Create a new user
   */
  @Post()
  create(@Body() createUserDto: CreateUserDto) {
    return this.usersService.create(createUserDto);
  }

  @Patch(':id/avatar')
  @UseGuards(JwtTwoFactorGuard)
  @UseInterceptors(FileInterceptor('avatar'))
  @UseInterceptors(ClassSerializerInterceptor)
  async updateAvatar(
    @UploadedFile(
      new ParseFilePipe({
        validators: [
          new MaxFileSizeValidator({ maxSize: 20000000 }), // max 20MB
          new FileTypeValidator({ fileType: /image\/(png|jpeg|svg\+xml)/ }), // accept svg, png and jpeg extensions
        ],
      }),
    )
    file: Express.Multer.File,
    @Param('id', ParseIntPipe) id: number,
  ) {
    const { filename } = file;
    const user = await this.usersService.updateAvatar(id, {
      avatar: filename,
    });
    return { user, file };
  }

  @Patch(':id')
  @UseGuards(JwtTwoFactorGuard)
  @UseInterceptors(ClassSerializerInterceptor)
  update(@Param('id') id: number, @Body() updateUserDto: UpdateUserDto) {
    return this.usersService.update(id, updateUserDto);
  }

  @Delete(':id')
  remove(@Param('id') id: number) {
    return this.usersService.remove(id);
  }
}
